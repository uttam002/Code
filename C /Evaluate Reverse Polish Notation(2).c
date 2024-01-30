// Problem Definition
// https://leetcode.com/problems/evaluate-reverse-polish-notation
int stack[10000];
size_t sp = 0;
void push(int val){
    stack[sp++] = val;
}

int pop(){
    return stack[--sp];
}

int evalRPN(char** tokens, int tokensSize) {
    for(int i = 0; i < tokensSize; i++){
        if(isdigit(tokens[i][0]) || (tokens[i][0] == '-' && isdigit(tokens[i][1]))){
            push((int)strtol(tokens[i], NULL, 10));
        }else{
            switch(tokens[i][0]){
                case '+':
                    push(pop() + pop());
                    break;
                case '-':
                    {
                        int r = pop();
                        push(pop() - r);
                    }
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '/':
                    {
                        int r = pop();
                        push(pop() / r);
                    }
                    break;
            }
        }
    }
    return stack[sp - 1];
}
