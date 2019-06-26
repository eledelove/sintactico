#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

class cAnalisisSintactico{

string tokenActual;
int i, numtokens;
string tokens[30];
ifstream inPrograma;

public:
//constructor
cAnalisisSintactico(){

    i=-1;
    numtokens = 0;
    tokenActual="";

    inPrograma.open("programaTiny.txt");
    try{
    if(inPrograma.fail())
        throw 0;
    cout<<"Exito al abrir el programa"<<endl;
    }catch(int i){
        if(i=0){
            cerr<<"Error al abrir el programa a analizar"<<endl;
        }
    }
    recuperaTokens();
}

void recuperaTokens(){
    int j=0;
    while(!inPrograma.eof()){
        inPrograma>>tokens[j++];

    }
    numtokens = j;
}

void imprimeTokens(){

    for(int i=0; i<numtokens; i++){
        cout<<tokens[i]<<endl;
    }
}

void match(string tokenEsperado){

    if(tokenActual == tokenEsperado){
        tokenActual=obtenSigToken();
    }

    else cerr<<"Error en Match";
}

string obtenSigToken(){

    return tokens[++i];
}


void programa(){
    //Token Actual inicializa vacio
    tokenActual=obtenSigToken();
    secuencia_sent();

    if(tokenActual != "")
        cout<<"Error en programa"<<endl;
}

void secuencia_sent(){
    sentencia();
    //secuencia_sent();

}

void sentencia(){

    if(tokenActual == "if")
        sentencia_if();
    else if(isalpha(tokenActual[0]))
        sentencia_asignacion();
}

void sentencia_if(){

    match("if");
    expresion();
    match("then");
    secuencia_sent();
    if(tokenActual == "end") match("end");
    else if(tokenActual == "else"){
        match("else");
        secuencia_sent();
        match("end");
    }
    else cerr<<"Error en la secuencia_if";
}

void sentencia_repeat(){

}

void sentencia_asignacion(){
    if(isalpha(tokenActual[0])){
        tokenActual = obtenSigToken();
        match(":=");
        expresion();
    }
    else cerr<<"Error en sent assig";
}

void sentencia_read(){

}

void sentencia_writet(){

}

void expresion(){
    exp_simple();
    if(tokenActual == "=" || tokenActual == "<"){ //(*pendiente a ejecutar)
        match(tokenActual);
        exp_simple();
    }

}

void exp_simple(){

    termino();
    //tokenActual = obtenSigToken();
    if(tokenActual == "+" || tokenActual == "-")
        APrima();

}

void APrima(){
    if(tokenActual == "+" || tokenActual == "-"){
        match(tokenActual);
        termino();
    }
    if(tokenActual == "+" || tokenActual == "-")
    APrima();
}

void termino(){

    factor();
    if(tokenActual == "*" || tokenActual == "/"){
        BPrima();
    }


}

void BPrima(){

    if(tokenActual == "*" || tokenActual == "/"){
        match(tokenActual);
        factor();
    }
    if(tokenActual == "*" || tokenActual == "/")
        BPrima();
}


void factor(){
    if(tokenActual == "("){
        match("(");
        expresion();
        match(")");

    }

    else if(isalpha(tokenActual[0]) || tokenActual[0] == '_'){

        match(tokenActual);
    }
    else if(isdigit(tokenActual[0])){
        match(tokenActual);
    }
    else cerr<<"Error en el factor";
}

};

int main(){
    cAnalisisSintactico miAnalisis;
    //miAnalisis.imprimeTokens();
    miAnalisis.programa();
    return 0;
}
