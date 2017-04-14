#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int * a;
    int top;
}SeqStack;
void push(SeqStack * pS, int X);
int pop(SeqStack * pS);
void solve(int * pre, int * in, int * post, int preL, int inL, int postL, int n);

int main()
{
//    freopen("in.txt", "r", stdin); // for test
    int i, N;
    scanf("%d", &N);
   
    SeqStack S;
    S.a = (int *)malloc(N * sizeof(int));
    S.top = -1;
    int pre[N], in[N], post[N];
    
    char chars[5];
    char * str = chars;
    int X, pre_index, in_index;
    pre_index = in_index = 0;
    for(i = 0; i < 2 * N; i++)
    {
        scanf("%s", str);
        if(strcmp(str, "Push") == 0)
        {
            scanf("%d", &X);
            pre[pre_index++] = X;
            push(&S, X);
        }
        else
            in[in_index++] = pop(&S);
    }
   
    solve(pre, in, post, 0, 0, 0, N);
    for(i = 0; i < N; i++)
    {
        printf("%d", post[i]);
        if(i < N - 1)
            printf(" ");
        else
            printf("\n");
    }
//    fclose(stdin); // for test
    return 0;
}

void push(SeqStack * pS, int X)
{
    pS->a[++(pS->top)] = X;
}

int pop(SeqStack * pS)
{
    return pS->a[pS->top--];
}

void solve(int * pre, int * in, int * post, int preL, int inL, int postL, int n)
{
    int i, root, L, R;
   
    if(n == 0)
       return;
    if(n == 1)
    {
        post[postL] = pre[preL];
        return;
    }
    root = pre[preL];
    post[postL + n - 1] = root;
    for(i = 0; i < n; i++)
        if(in[inL + i] == root)
            break;
    L = i;
    R = n - L - 1;
    solve(pre, in, post, preL + 1, inL, postL, L);
    solve(pre, in, post, preL + L + 1, inL + L + 1, postL + L, R);
}
