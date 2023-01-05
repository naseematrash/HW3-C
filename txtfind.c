#include <stdio.h>
#include <string.h>

#define LINE 256
#define WORD 30


 
int get_line(char s[]) {
    int i = 0;

    for (i = 0; i < LINE; ++i)
    {
        if (scanf("%c", &s[i]) == EOF)
        {
            s[i] = '\0';
            break;
        }

        if (s[i] == '\n')
        {
            s[i] = '\0';
            break;
        }
    }

    if (i == LINE)
        s[i - 1] = '\0';

    
    else if (s[i] == '\r')
        s[i++] = '\0';

    return i;
}






int getword(char w[]) {
    int i = 0;

    for (i = 0; i < WORD; ++i)
    {
        if (scanf("%c", &w[i]) == EOF)
        {
            w[i] = '\0';
            break;
        }

        if (w[i] == '\n' || w[i] == '\t' || w[i] == ' ')
        {
            w[i] = '\0';
            break;
        }
    }

    if (i == WORD)
        w[i - 1] = '\0';

    return i;
}







int substring(char * str1, char * str2) {
    int str1_len = strlen(str1);
    int str2_len = strlen(str2);
    int c ;

    for (int i = 0; i <= str1_len - str2_len; ++i)
    {
        c = 0;

        for (int j = 0; j <= str2_len; ++j)
        {
            if (*(str1 + i + j) == *(str2 + j))
                ++c;
        }

        if (c >= str2_len)
            return 1;
    }

    return 0;
}







int similar(char *s, char *t, int n) {
    int s_len = strlen(s);
    int t_len = strlen(t);
    int i = 0;
    int j = 0;

    if (s_len - t_len != n)
        return 0;

    for (i = 0; i < s_len && j < t_len; ++i)
    {
        if (*(s + i) == *(t + j))
            ++j;
    }

    return (t_len == j);
}








void print_lines(char * str) {
    char line[LINE] = { 0 };

    while(get_line(line) != 0)
    {
        if (substring(line, str) != 0)
            printf("%s\n", line);
    }
}





void print_similar_words(char * str) {
    char word[WORD] = { 0 };

    while(getword(word) != 0)
    {
        if (similar(word, str, 1) || similar(word, str, 0))
            printf("%s\n", word);
    }
}




int main() {
    char word[WORD];
    char choice;

    getword(word);
    scanf(" %c\n", &choice);

    if (choice == 'a')
        print_lines(word);

    else if (choice == 'b')
        print_similar_words(word);

    return 0;
}
