#include "BancoDePalavras.h"

// construtor
BancoDePalavras::BancoDePalavras(std::default_random_engine& maquinaAleatoria)
    : maquinaAleatoria(maquinaAleatoria)
{  
    carregaBancoDePalavras();
}

// sorteia a palavra do banco de palavras
std::string BancoDePalavras::pegaPalavraAleatoria() const {
    return palavras[maquinaAleatoria() % NUM_PALAVRAS];  
}

// carrega os elementos (palavras) no vetor
void BancoDePalavras::carregaBancoDePalavras() {
    palavras = new std::string[NUM_PALAVRAS]{ "ADRESS", "ALWAYS", "ASSIGN", "BACKUP", "BINARY", "BRANCH",  "BUFFER",
        "CURSOR", "DECODE", "DEFINE", "DELETE", "DEVOPS", "DOCKER", "DOUBLE", "DRIVER", "FINISH", "FRIEND", "GLOBAL", 
        "HACKER", "HANDLE", "HAZARD", "HEADER", "INLINE", "LINKER", "MALLOC", "MEMORY", "MODULE", "NUMBER", "OBJECT", 
        "OFSSET", "ONLINE", "OPCODE",  "OUTPUT", "PROLOG" "PROMPT", "PUBLIC", "PYTHON", "RANDOM", "REBOOT", "REPEAT",
        "SCROLL", "SEARCH", "SERVER", "SPRITE", "STATIC", "STATUS", "STRING", "STRUCT", "SYNTAX", "SYSTEM",  "UPDATE", 
        "UPLOAD", "VECTOR", "WINDOW" };
}
