set target_directory $argv[1]
set days_inactive $argv[2]
set recursive $argv[3]
set dry_run $argv[4]
set excluded_files_dirs $argv[5]
set sort_type $argv[6]
set confirmation $argv[7]

# Check if the function has 7 args
if test (count $argv) -ne 7
    echo "Correct formfactor:"
    echo "function cleanup(target_directory, days_inactive, recursive, dry_run, excluded_files_dirs, sort_type, confirmation)"
    exit 1
end

# fix the way argv[5] is written
if not test -z "$excluded_files_dirs"
    set excluded_files_dirs (echo $excluded_files_dirs | tr ',' '\n') #translate comma into enter
    for dirs in $excluded_files_dirs
        set all_excluded $all_excluded -not -name $dirs
    end    
end

# Recursive parameter, inactivity, excluded files and dirs
if test $recursive = true
    set to_be_deleted (find $target_directory -type f $all_excluded -atime +$days_inactive -o -type d $all_excluded -atime +$days_inactive) #exclusions must be after each type
else if test $recursive = false
    set to_be_deleted (find $target_directory -maxdepth 1 -type f $all_excluded -atime +$days_inactive -o -maxdepth 1 -type d $all_excluded -atime +$days_inactive)
else 
    echo "Error: neither true or false recursive parameter"
end
# for debugging: echo "del: $to_be_deleted"

# Manage empty $to_be_deleted output
if test -z "$to_be_deleted"
    echo "List empty. There is nothing to delete :)"
    exit 0
end

# Sort files by size
switch $sort_type
case "desc"
    set sorted_list (echo $to_be_deleted | xargs -n 1 du -h | sort -hr) #pipelines(symbol: | )the output of echo, to the xargs, to sort
case "asc"
    set sorted_list (echo $to_be_deleted | xargs -n 1 du -h | sort -h)
case "*"
    echo "Unknown sort type: $sort_type"
    exit 1
end
# sorted_list displays the size of the files/dirs and 
# is created in order to be able to store somewhere this info 
# without ruining our original var $to_be_deleted
# for debugging: echo "sort: $sorted_list"

# Dry run mode
if test $dry_run = true
    echo "Dry_run mode enabled - Files that would have been deleted:"
    for line in $sorted_list
        echo $line
    end
    exit 0
else if test $dry_run = false 
    echo "Dry_run mode disabled - Files to be deleted:"
    for line in $sorted_list
        echo $line
    end
else
    echo "Invalid dry_run input. Use either: true or false"
    exit 1
end

# Ask for user confirmation    
if test $confirmation = true
    read -P "Do you really want to delete these files/dirs(and the files they contain)? (y/n) " -n 1 -l confirm
    #-p prompt(the text), -n number of characters('y' so 1), -l list store the user input into confirm
    if not test "$confirm" = "y"
        echo "Cleanup aborted."
        exit 0
    end
end
echo
find $to_be_deleted -exec rm -r -f {} + 
echo "Cleanup completed."