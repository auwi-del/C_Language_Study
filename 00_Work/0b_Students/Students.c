#include <stdio.h>
#include <string.h>

#include "List.c"
#include "Menu.c" 

// #define DEBUG
#define FILENAME "save.txt"

int Editor( List* LIST );           // ���� [��������] ��ָ��, ����Ĺ���, ����ܾ����ڴ�
int Save( List *LIST, char *fileName );     // ���浽�ļ���ͷ
int Read( List *LIST, char *fileName );     // ���ļ���ͷ��ȡ��������
int Confirm();                      // ȷ���û�����
int GetInput_help();                // ��ʾ�����˵�
int Average( Node *NODE, int len ); // �����ڵ���ƽ��
int ListAvg( List *LIST );          // ȫ���ݴ�������ƽ��

// main �� main 
#ifndef DEBUG

int main()
{
    int i, j, k;
    int input;

    List* students = mkList();

    while(1)
    {
        DrawMenu();
        // scanf( "%d", &input );
        // getchar();              // get�� '\n'

        printf("\t");
        system( "pause" );

        if ( /*input ==*/ 1 )
        {
            Editor( students );
            see_the_list( students );
        }
        
    }

    system( "pause" );
    
}

#endif



// ��ȡ����Ĺ���
//  ��ȡ�û������룬 ֱ���û����� 'exit' ���˳�
 
int Editor( List* LIST )
{
    Node* p = LIST -> last;         // Ŀ����������βָ����
    int a, b, c, d, e, i, j, SCANED;
    
    // ��ӡ�����ĵ�.
    GetInput_help();
    
    char input[ 10 ] = {};
    while( 1 )
    {
        // ��ȡ����, ���������, �Ǿ�����, �������, �ǾͰ��������
        for ( i = 0; i < STRLEN; i++ )
        {
            input[i] = getchar();
            if ( ( input[i] == ' ' ) || ( input[i] == '\n' ) )
            {
                input[i] = '\0';        // ������
                break;
            }
        }

        // ����: exit
        if( !strcmp( input, "exit" ) )
        {
            printf( "�������\n" );
            break;
        }

        // ����: save
        if( !strcmp( input, "save" ) )
        {
            printf( "���潫�Ḳ�����д浵�ļ�, �Ƿ񱣴�? ( y / n )\n" );
            if( Confirm() )
            {
                printf( "��ʼ����...\n" );
                Save( LIST, FILENAME );
                printf( "������ɣ�\n");
            } else {
                printf( "��ȡ��, ������������.\n" );
            }
            

            continue;
        }

        // ����: read
        if( !strcmp( input, "read" ) )
        {
            printf( "��ȡ���Ḳ��������������, �Ƿ��ȡ? ( y / n )\n" );

            if( Confirm() ) {
                printf( "\n��ʼ��ȡ...\n" );
                Read( LIST, FILENAME );         // ��ȡ
                p = LIST->last;                 // ָ��ָ�����Ľڵ�, �ýڵ�Ϊ��, ������д��
                printf( "��ȡ��ɣ�\n������������\n\n");
            } else {
                printf( "��ȡ��, ������������.\n" );
            }
            continue;
        }

        // ����: avge
        if( !strcmp( input, "avge" ) )
        {
            printf( "��ʼ����ƽ����\n" );
            ListAvg( LIST );
            see_the_list( LIST );
            printf( "\n\nƽ�����������!\n\n");
            continue;
        }

        // ����: sort
        if( !strcmp( input, "sort" ) ) 
        {
            printf( "��ʼ����\n" );
            LIST = Sort( LIST );
            p = LIST->last;         // LIST������λ��, p�ñ���!!
            see_the_list( LIST );

            printf( "\n\n�������!\n\n");
            continue;
        }

        // ����: see
        if( !strcmp( input, "see" ) )
        {
            see_the_list( LIST );
            printf( "�������������ݴ������, ���������:\n" );
            continue;
        }

        // ����: help
        if( !strcmp( input, "help" ) )
        {
            GetInput_help();
            continue;
        }
        
        strcpy( p -> name, input);              // ��char* inputд��p->name
        
        // ��ֵ������
        // ��һ��һ��Ҫ�����ĩβ�� '\n' ��.
        SCANED = scanf( "%d, %d, %d, %d, %d", &(p->score[0]), &(p->score[1]), &(p->score[2]), &(p->score[3]), &(p->score[4])  );
		Average( p, 5 );
        while( getchar() != '\n' );              // ��ʣ�µ��ַ�һ�ʴ���
		
        

		// ���scanf�˶��ٸ� 
		if ( SCANED <= 1 )
        {
            printf( "��ȡ���� ���� ��������1��!(����exit���˳��ؽ�)\n" );
            continue;
        }
			
		
        Node_add( LIST );
        p = p->Next;
    }
}


/*
=================================================================================

						   �� �� �� д 


�ļ��Ľṹ:
+++++++++++++++++++++++++++  [ save.stu ] +++++++++++++++++++++++++++++++++

[ (int)����ĳ���n ]
1 [ char name[10] ], score[0], scor[1], scor[2], ..., scor[10],\n
2 [ �ڵ�2 ] 
...
n [�ڵ�n]
end

---------------------------- �������� -------------------------------------
�ļ��Ľṹ��
�� һ���м����ڵ㣨int��n��
�� �ڵ�1 ��
�� �ڵ�2 ��
...  
�� �ڵ�n��
 
=================================================================================
*/ 


// ����Ҫ��д���[��������ṹ]��[�ļ���ָ��] 
int Save( List *LIST, char *fileName )
{
    int i, j, listLen = LIST->length, num/*��ʱ�Ĵ����*/;
    Node *p = LIST->head;                   // ָ��ǰ���ڴ���Ľڵ�, ��ʼָ��ͷ�ڵ�

    FILE *fp = fopen( fileName, "w+" );   // ���ļ�
    fprintf( fp, "listlen = %d\n", listLen );          // д��������
    
    for ( i = 0; i < listLen; i++ )
    {
        // 1, [ char name[10] ], score[0], scor[1], scor[2], ..., scor[10], ave,\n
        fprintf( fp, "%d, %s, ", i, p->name );
        for ( j = 0; j < SCORLEN; j++ )
        {
            num = p->score[j];
            fprintf( fp, "%d, ", num );
        }
        fprintf( fp, "%.2f, ", p->ave );          // д��ƽ����
        fprintf( fp, "\n" );
        p = p->Next;
    }
    fclose( fp );

}

// ���� ( [��������ṹ], "�ļ�.��չ��" ), �˺��������ļ��ڵ����ݶ�ȡ������ LIST ��
int Read( List *LIST, char *fileName )
{
    int i, j, num, listLength;
    char c;
    Node *p = LIST->head;           // p ��Ȼ�ǵ�ǰ���ڶ�д�Ľڵ�

    FILE *fp = fopen( fileName, "r+" );

    fscanf( fp, "listlen = %d", &listLength );                      // ��ȡ������

    for( i = 0; i < listLength - 1; i++ )       // save �ļ����һ��Ϊ������, ��Ҫ��ȡ
    {
        // 1, [ char name[10] ], score[0], scor[1], scor[2], ..., scor[10],\n
        fscanf( fp, "%d, %s, ", &num, (p->name) );


        // ȥ�� scanf() �ڶ�ȡ����ʱһ����������','
        for( j = 0; j < STRLEN; j++ )           
        {
            c = p->name[ j ];
            if( c == ',' )
            {
                p->name[ j ] = '\0';
                break;          // ֱ������ѭ��
            }
        }

        // ��ȡ����
        for( j = 0; j < 10; j++ )
        {
            fscanf( fp, "%d, ", &( p->score[j] ) );
        }

        // ��ȡС��
        fscanf( fp, "%f, ", &( p->ave ) );

        // �ж��Ƿ���Ҫ���ӽڵ�, �����ӽڵ�
        if( p->Next == NULL )             // ���, ��ǰ�ڵ����һ�ڵ�, û����һ�ڵ�, ��:
            if( i < listLength - 1 )            // i ���ջ���� listlength, ����Ӧ����ǰһ��, ��������һ�� Node
                Node_add( LIST );

        p = p->Next;
    }
    see_the_list( LIST );

    fclose( fp );
}


// ���ñ�����, �����ն˶�ȡһ���ַ�, y����1, n����0, ������Ҫ���û���������
int Confirm()
{
    int result = -1;
    char c;
    while(1)
    {
        c = getchar();
        if( c == 'y' )
        {
            result = 1;
            break;
        }
        else if( c == 'n' )
        {
            result = 0;
            break;
        }
        else 
        {
            printf( "δ֪����, ����������:\n" );
            while( getchar() != '\n' );
            continue;
        }
    }
    getchar();
    return result;
}


// ��򵥵��Ĳ鿴
int GetInput_help()
{
    printf( "\n\n\n**************   ��Ϣ�����༭��   *****************\n" );
    printf( "��: \nܽ�� 100,100,100,100,100\\n \n" );
    printf( "��ʽΪ: ���� [�ո�] ����1 ���� ����2 ���� ����3 ���� ����4 ���� ����5 �س�\n");
    printf( "���ֺ����Ҫ�пո�, �������ʶ�� 5 ������\n" );
    printf( "\n***����scanf()����: \n***�û����������ֺ�δ�����κ����ֲ����л���ɳ���û�з�Ӧ\n");
    printf( "***��ʱ�������ӵ��Ǹ�����, ֱ�ӽ��Ű���ʽ����5������,\n");
    printf( "***Ҳ������������5�����ϵĶ���, �س�, \n***���򱨴���������� exit, ���½��뱾����, ��������\n\n" );
    printf( "��������һ���������������, �����ε����õ�����\nΪȷ����Ϣ����ʧ, �뾡���ϸ��������ʽ��������!\n" );
    printf( "\n\n��������:\nexit\t�˳�\nsave\t���浽�ļ�(�ļ�����Դ�����к궨��)\nread\t���ļ��ж�ȡ����\n" );
    printf( "avge\t�����е��ݴ����ݽ�����ƽ��\nsort\tѡ������\nsee\t�鿴��ǰ�����ݴ������\nhelp\t������ʾ��������\n" );
    printf( "( �����������, ������Ϊ�� name ����! )\n\n" );
    
    // printf( "�������Ҫ��, ���Ժ��� [�༭] ��������ɾ�Ĳ�.\n" );
    printf( "*****************************************************\n\n\n\n" );
}

// ����( �ڵ�, ǰ��λ����Ч�� ), �˺�������ƽ��ֵ������ NODE->ave ��.
int Average( Node *NODE, int len )
{
    int i, sum;
    float result;
    for( i = 0; i < len; i++ )
    {
        sum += NODE->score[i];
    }
    NODE->score[6] = sum;       // score[6] �������ܷ�
    result = sum / len;         // ����
    NODE->ave = result;         // ����
}

// ����( ����, ���� ), ���������������ƽ��, ������LIST->avg��.
int ListAvg( List *LIST )
{
    int listlen = LIST->length - 1, i, j;
    Node *p = LIST->head;
    
    for( i = 0; i < listlen; i++ )
    {
        Average( p, 5 );
        if( p->Next != NULL )
            p = p->Next;
    }
}

#ifdef DEBUG
int main()
{
    Save();
}

#endif





