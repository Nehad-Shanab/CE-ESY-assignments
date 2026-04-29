#include <stdio.h>
#include <string.h>
#define size 20
typedef struct {
    char buffer[size];
    int head;
    int tail;
    int count;
}
CircularBuffer;
void init (CircularBuffer *cb){
    cb->head =0;
    cb->tail =0;
    cb->count =0;
}
int isFull(CircularBuffer *cb){
    return (cb->count==size);
}
int isEmpty(CircularBuffer *cb){
    return(cb->count==0);
}
void write(CircularBuffer *cb,char Data){
    if(isFull(cb)){
        printf("buffer overflow\n");
        return;
    }
    cb->buffer[cb->tail]=Data;
    cb->tail=(cb->tail+1)%size;
    cb->count++;
}
char read(CircularBuffer *cb){
    if(isEmpty(cb)){
        printf("buffer underflow\n");
        return'\0';
    }
    char Data = cb->buffer[cb->head];
    cb->head=(cb->head+1)%size;
    cb->count--;
    return Data;
}
int main() {
    CircularBuffer cb;
    char input[100];
    char finalText[200];
    printf("Enter your name: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';
    snprintf(finalText, sizeof(finalText), "%sCE-ESY", input);
    int L = strlen(finalText);
    // Small Test (Overflow)
    printf("\n--- Small Buffer Test (Overflow expected) ---\n");
    init(&cb);
    for (int i = 0; i < 5; i++) {
        write(&cb, finalText[i]);
    }
    printf("Output: ");
    while (!isEmpty(&cb)) {
        char ch = read(&cb);
        putchar(ch);
    }
    printf("\n");
    //  Large Test (No Overflow)
    printf("\n--- Large Buffer Test (No Overflow) ---\n");
    init(&cb);
    for (int i = 0; i < L ; i++) {
        write(&cb, finalText[i]);
    }
    printf("Output: ");
    while (!isEmpty(&cb)) {
        char ch = read(&cb);
        putchar(ch);
    }
    printf("\n");
    return 0;
}
