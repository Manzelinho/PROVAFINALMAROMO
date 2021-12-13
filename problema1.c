#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char MatrizAlunos[4][2][70] = {
        {"12131", "cbabcadeacbaeabdeaeaabcdaeeaabdaabdeaeaabceaaaaaa"},
        {"12233", "abdeaeaabcdaeeaabdaabdeaeadeaeaabcdaeeaabdaabbbba"},
        {"13311", "cbabcadeacbaeabdeaeaabcdaeeaabdaabdeaeaabcebbabcaa"},
        {"14411", "eabdeaeaabcdaeeaabdaaeaabcdaeeaaeaeaabcdaeeabcabca"}};

    char Gabarito[51] = "abcdeedcbaabcdeedcbaabcdeedcbaabcdeedcbaabcdeedcba";
    
    char pontuações[4][2][5];

    for (int i = 0; i < 4; i++)
    {
        int acertos = 0;
        char Aluno[5];
        strcpy(Aluno, MatrizAlunos[i][0]);

        for (int z = 0; z < 51; z++)
        {
            char questao = MatrizAlunos[i][1][z];

            if (questao == Gabarito[z])
            {
                acertos++;
            }
        }

        printf("%s - %d | ", Aluno, acertos);        
        strcpy(pontuações[i][0][5], Aluno);
        strcpy(pontuações[i][1][5], acertos);
        acertos = 0;
    }


    return 0;
}
