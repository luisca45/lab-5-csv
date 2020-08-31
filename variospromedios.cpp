#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <stdio.h>
using namespace std;

double promedios_individuales(const char* archivocvv)
{
    int l=0;
    double promedio[4];
    double final;
    double numero;
    double sumavaria=0;
    double a=0;
    ifstream data(archivocvv);//creamos el objeto data para importar el archivo .csv
    string line;
    vector<vector<string>> parsedCsv;
    int rowcount=0;
    int colcount=0;
    while (getline(data,line))// ciclo el cual extrae los elemntos del objeto data y los guarda en el string "line"
    {
        stringstream lineStream(line);
        string cell;
        vector<string> Row;
        colcount=0;
        while (getline(lineStream,cell,','))//Se extrae el contenido de la clase "lineStream" para luego guardarlos en el string cell y se usa un delimitante "," para separar los elementos
        {
            Row.push_back(cell);
            colcount++;

        }
        rowcount++;
        parsedCsv.push_back(Row);  //se ponen los valores dentro del vector
    }
    float sumatoria=0;

    for(int y=2; y<colcount;y++){ //se calcula el promedio individual de las filas
        for(int x=0; x<rowcount;x++ ){
        float suma=std::stof(parsedCsv[x][y]);
        sumatoria=(suma+sumatoria);
        }
        sumatoria=sumatoria/rowcount;
        l++;
        cout << sumatoria <<" "<< l << "fila";

        a=sumatoria+a;
        sumatoria=0;
        cout <<'\n';
    }
    for (int i=0; i<4 ;i++){//se calcula el promedio global y se imprime

        promedio[i]=a/4;
        numero=promedio[i];    
        sumavaria=numero+sumavaria;  
        final=sumavaria/4;
     }
    cout<<"promedio final:"<<" "<< final;
    cout <<'\n';
}

int main()
{
    cout << "El promedio de la nota de 5 estudiantes es: "<<'\n';
    promedios_individuales("Promedio5Estud.csv");
    cout << "El promedio de la nota de 10 estudiantes es: "<<'\n';
    promedios_individuales("Promedio10Estud.csv");
    cout << "El promedio de la nota de 15 estudiantes es: "<<'\n';
    promedios_individuales("Promedio15Estud.csv");
    cout << "El promedio de la nota de 20 estudiantes es: "<<'\n';
    promedios_individuales("Promedio20Estud.csv");
    return 0;}