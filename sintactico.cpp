#include <iostream>
using namespace std;

class cAnalisisSintactico{

string tokenActual;
int i;
string tokens[30];

public:
//constructor
cAnalisisSintactico(){

    i=0;
    tokenActual="";
    recuperaTokens();

}

void recuperaTokens(){
    //llenar el arreglo tokens
}

void match(string tokenEsperado){

    if(tokenActual == tokenEsperado)
        tokenActual=obtenSigToken();

    else cerr<<"Error";
}

string obtenSigToken(){

    return tokens[++i];
}


void programa(){
    secuencia_sent();
}

void secuencia_sent(){
    secuencia_sent();

}

void sentencia_if(){

}

void sentencia_repeat(){

}
void sentencia_asignacion(){

}
void sentencia_read(){

}
void sentencia_writet(){

}
void expresion(){
    exp_simple();
    if(tokenActual == "=" || tokenActual == "<")
        exp_simple();

}
void exp_simple(){

    termino();
    tokenActual = obtenSigToken();
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

}
void factor(){
    if(tokenActual == "("){
        match("(");
        expresion();
        match(")");

    }

    else if(isalpha(tokenActual[0]) || tokenActual[0] == '_'){


    }
    else if(isdigit(tokenActual[0])){

    }
    else cerr<<"Error en el factor";
}



};

int main(){

    cout<<"Hola Ionhatan" <<endl;
    return 0;
}
