#define MAX_SIZE 3000

struct Stack {
    int digits[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

// Function to check if the stack is full
int isFull(struct Stack *stack) {
    return (stack->top == MAX_SIZE - 1);
}

// Function to push an element onto the stack
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
    } else {
        stack->top++;
        stack->digits[stack->top] = value;
    }
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    int poppedItem;
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1; // Returning a dummy value; you might want to handle this differently based on your application
    } else {
        poppedItem = stack->digits[stack->top];
        stack->top--;
        return poppedItem;
    }
}

int evalRPN(char** tokens, int tokensSize) {
    struct Stack stack;
    initialize(&stack);
    
    int op1,op2;
    for(int i=0;i<tokensSize;i++){
        char *ch = tokens[i];
        
        if (strlen(ch)==1 && (ch[0]=='+' || ch[0]=='-' || ch[0]=='*' || ch[0]=='/')){
            op2=pop(&stack);
            op1=pop(&stack);

            switch(ch[0]){
                case '+':
                push(&stack,(op1+op2));
                break;
                case '-':
                push(&stack,(op1-op2));
                break;
                case '*':
                push(&stack,(op1*op2));
                break;
                case '%':
                push(&stack,(op1%op2));
                break;
                case '/':
                push(&stack,(op1/op2));
                break;
            }
        }
        else {
            push(&stack, atoi(ch));
        }
    }
    return pop(&stack);
    
}
