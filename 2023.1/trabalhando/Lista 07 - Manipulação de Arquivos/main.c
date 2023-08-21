#include <stdio.h>
#include <stdlib.h>
#include "bmp_utils.h"

int main(int argc, char* argv[]) 
{
    BMPData *bmp_data = NULL;
    BMPFileHeader file_header;
    BMPHeader bmp_header;


    // TODO: (QUESTÃO 1) Modifique o programa para receber o nome dos arquivos 
    // via linha de comando. 
    // Use o nome do arquivo de entrada no lugar de "fig1.bmp". 
    // Use o nome do arquivo de saída para escrever o novo BMP.
    char* input_ = argv[1];
    char* output_ = argv[2];

    bmp_data = bmp_read(input_, &file_header, &bmp_header);

    if (bmp_data == NULL)
    {
        printf("Unable to process file\n");
        exit(1);
    }

    // TODO: (QUESTÃO 2) Implemente um filtro que transforma uma imagem  
    // colorida de 24 bits por pixel em uma imagem em tons de cinza.
    //
    // Os tons de cinza possuem o mesmo valor para as cores R(vermelho), 
    // G(verde) e B(azul). 
    // Uma possível transformação é:
    // tom de cinza = (R*0.11) + (G*0.59) + (B*0.3)

    unsigned int bmp_size = bmp_header.biWidth * bmp_header.biHeight;
    for (unsigned int i = 0; i < bmp_size; i++) {
        unsigned char gray_value = (unsigned char)((bmp_data[i].r * 0.11) + (bmp_data[i].g * 0.59) + (bmp_data[i].b * 0.3));
        
        bmp_data[i].r = gray_value;
        bmp_data[i].g = gray_value;
        bmp_data[i].b = gray_value;
    }



    // TODO: (QUESTÃO 3) Salve a imagem modificada em um novo arquivo BMP
    // Para isso é necessário implementar a função bmp_write() na biblioteca
    // bmp_utils.
    // TODO: (QUESTÃO 3) Salve a imagem modificada em um novo arquivo BMP
    if(argv[2]==NULL){
        output_ = "imagem_cinza.bmp";
    }
    bmp_write(output_, &file_header, &bmp_header, bmp_data);
    
    // TODO: (QUESTÃO 4) Libere a memória com malloc() que ainda não foi liberada.
    free(bmp_data);

    return 0;
}

