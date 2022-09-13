#include <stdio.h>

void fibonacci(int, int, int, int);

void fibonacci(f, s, t, l) {
    int temp;
    if(t>l){
        return;
    }
    else{
        printf("%d ", f);
        t=t+1;
        temp=s;
        s=f+s;
        f=temp;
        fibonacci(f,s,t,l);
    }
}

int main(void) {
	int term, limit, first, second;
	term=1;
	limit=21;
	first=1;
	second=1;
	fibonacci(first, second, term, limit);
	printf("\n");
	return 0;
}

