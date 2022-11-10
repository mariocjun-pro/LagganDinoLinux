#pragma once
#include "stdafx.h"

//Classe Thread adaptada dos slides 18C do Prof. Dr. Jean Marcelo Simão
//http://www.dainf.ct.utfpr.edu.br/~jeansimao/Fundamentos2/ThreadsPosix/Fundamentos2-SlidesC++18C-2018-05-22_OO.pdf

namespace GerenciadoresEntidades {
    class PThread {
    public:
        PThread();
        virtual ~PThread();
        
        void iniciarThread();
        void juntarThread();
        void liberarThread();
        void fecharThread();
        void abrirThread();
        
    protected:
        pthread_t threadId;
        pthread_attr_t tAtributo;
        static pthread_mutex_t mutex;
                
        static void* executarThread(void* pThread);
        virtual void funcaoThread() = 0;

    };
}