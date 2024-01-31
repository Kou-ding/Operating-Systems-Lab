#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    void* data; //data: pointer to the data
    int size; //size: number of elements
    int capacity; //capacity: number of elements that can be stored
    int elemSize; //elemSize: size of each element
} Vector;

int vector_init(Vector* vec, int elemSize) {
    if(elemSize<0) return -1; // Check if the element size is valid
    vec->elemSize = elemSize; // Initialize element size
    vec->size = 0; // Initialize size
    vec->capacity = 100; // Initialize capacity
    vec->data=malloc(vec->elemSize*vec->capacity); // Allocate memory for the data
    // Return success code
    return 0;
}

void vector_destroy(Vector* vec) {
    free(vec->data); // Free the memory allocated for the data
    vec->data = NULL; // Set the data pointer to NULL
    vec->size = 0; 
    vec->capacity = 0;   
    vec->elemSize = 0;
}

int vector_push_back(Vector* vec, void* value) {
    // Check if there is enough capacity
    if(vec->size >= vec->capacity) {
        // If not, increase the capacity (double it, for example)
        vec->capacity *= 2;
        // Reallocate memory for the new capacity
        vec->data = realloc(vec->data, vec->capacity * vec->elemSize);
        if(vec->data == NULL) {
            // If realloc failed, handle the error
            return -1;
        }
    }

    // Copy the new element to the end of the vector
    memcpy((char*)vec->data + vec->size * vec->elemSize, value, vec->elemSize);
    vec->size++;
    // Return success code
    return 0;
}

int vector_pop(Vector* vec, void* out) {
    // Check if the vector is empty
    if(vec->size == 0) {
        // If it is, return an error code
        return -1;
    }

    // Copy the last element to the output
    memcpy(out, (char*)vec->data + (vec->size - 1) * vec->elemSize, vec->elemSize);

    // Decrease the size of the vector
    vec->size--;

    // Return success code
    return 0;
}

int vector_remove(Vector* vec, int index) {
    // Check if the index is valid
    if(index < 0 || index >= vec->size) {
        // If it's not, return an error code
        return -1;
    }

    // Shift all elements after the index back by one position
    memmove((char*)vec->data + index * vec->elemSize, 
            (char*)vec->data + (index + 1) * vec->elemSize, 
            (vec->size - index - 1) * vec->elemSize);

    // Decrease the size of the vector
    vec->size--;

    // Return success code
    return 0;
}

int main(void){
    Vector vec;
    //vec.capacity = 10;
    vector_init(&vec, sizeof(int));
    int val = 4;
    vector_push_back(&vec, &val); // Pass the address of the value
    val = 3;
    vector_push_back(&vec, &val); // Pass the address of the value
    for(int i = 0; i < vec.size; i++){
        printf("%d\n", *(int*)((char*)vec.data + i * vec.elemSize));
    }
    vector_remove(&vec, 0);
    printf("--------------------------\n");
    for(int i = 0; i < vec.size; i++){
        printf("%d\n", *(int*)((char*)vec.data + i * vec.elemSize));
    }
    return 1;
}