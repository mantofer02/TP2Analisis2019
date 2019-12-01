#ifndef DICCIONARIO_H
#define DICCIONARIO_H
#include <vector>

using namespace std;

template <class T>
class Diccionario
{
    public:
        vector<T> diccionario;
        
        void iniciar(){
            
        }

        void agregar(T vertice){
            diccionario.push_back(vertice);
        }

        bool pertenece(T vertice){
            bool encontrado = false;
            typename vector<T>::iterator it;
            for(it=diccionario.begin(); (it<diccionario.end()) && !encontrado; it++){
                if(*it == vertice){
                    encontrado = true;
                }
            }
            return encontrado;
        }
        
        void destruir() {
			//~Diccionario();
		}
		
		int numElem() {
			return diccionario.size();
		}
		
		void pop() {
			int amount_elements = numElem(); 
			diccionario.erase(diccionario.begin()+amount_elements); 
		}

        virtual ~Diccionario(){
        }
};

#endif // DICCIONARIO_H
