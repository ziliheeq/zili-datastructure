typedef char* string;
void getNext(string T, int* next) {
    int i, j;
    i = 1; 
    j = 0;
    next[1] = 0;

    while (i < T[0]) {
        if(j == 0 || T[i] == T[j]) {
            ++i;
            ++j;
            next[i] = j;
        }
        else {
            j = next[j];
        }
    }
}