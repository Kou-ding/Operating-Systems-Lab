# Operating-Systems-Lab
This repository is comprised of the accumulated knowledge of the course: "Operating Systems" 2023-2024

### Useful Notes
```bash
# To connect via ssh:
sudo ssh -p 993 username@serverIP
# -p 993 is in case you have to connect to a specific port (for example, here: 993)
# Password-less ssh via fingerprint:
# on local machine do: $ ssh-keygen 
# this creates a public and a private key
# Navigate to ./ssh and execute the following command:
ssh-copy-id -i id_rsa.pub -p 993 username@serverIP
# Now you will be prompted for the password one final time and from now on you won't have to enter your password ever again
```


## Things we learned:
- [x] fish, as an alternative to bash
- [x] Filezilla, connecting and downloading files from servers
- [x] ssh, remote connection to servers
- [x] ssh-keygen
- [x] Fingerprint SSH connection establishment 