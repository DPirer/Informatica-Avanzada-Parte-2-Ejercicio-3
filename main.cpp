// EJERCICIO 3

// AUTOR: PEDRO ESTÉVEZ

/* Cree un vector que contenga los números enteros del 1 al 10 (en ese orden)
•Elimine los números pares
•Invierta el orden de los elementos del vector
•Inserte los números pares en el lugar que les corresponda en el nuevo orden
•Imprima el contenido del vector (puede usar la función printVector del ejercicio
anterior) */

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

/* vector.erase sirve para eliminar un elemento o rango de elementos, pues encuentra la posición que quieres eliminar
 * la elimina y reorganiza el vector, de forma que 1. es muy costoso y 2. hacer esto en un for es imposible porque se
 * cambian los índices del iterador resultando de vez en cuando en un error de segmentación.
 *
 * La solución es usar std::remove, que elimina la posición deseada sin modificar el vector. Sólo cuando termina de recorrer
 * el vector es cuando lo reorganiza, de forma que sí podemos recorrer el vector correctamete, pero tenemos que quedarnos
 * con la última posición del elemento, porque los reorganiza, no elimina
 *
 * En cualquier caso, es más fácil crear vectores nuevos*/

int main()
{
    vector <int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector <int> v_pares, v_impares, r_v, v_final;
    vector <int>::iterator it;

    // Mostramos el vector original
    cout<<"El vector inicial es: [ ";
    for (it = v.begin(); it != v.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<"]"<<endl;

    // Recorremos el vector mostrando los números pares y creando otro vector con ellos
    cout<<"Los numeros pares son: [ ";
    for (it = v.begin(); it != v.end(); ++it){
        if ((*it % 2) == 0){
            v_pares.push_back(*it);
            cout<<*it<<" ";
        }
    }
    cout<<"]"<<endl;

    // Recorremos el vector mostrando los números impares y creando otro vector con ellos
    cout<<"Los numeros impares son: [ ";
    for (it = v.begin(); it != v.end(); ++it){
        if ((*it % 2) == 1){
            v_impares.push_back(*it);
            cout<<*it<<" ";
        }
    }
    cout<<"]"<<endl;

    // Recorremos el vector al revés y lo almacenamos en otra variable
    // vector<int>::reverse_iterator rit; Por algún motivo, el reverse iterator da error
    cout<<"El vector al reves es: [ ";
    for (it = (v_impares.end() -1); it >= v_impares.begin(); --it){
        r_v.push_back(*it);
        cout<<*it<<" ";
    }
    cout<<"]"<<endl;

    // Seguramente si voy insertando elementos en el vector me pase lo mismo que al sacarlos, el tamaño del
    // vector variará en cada iteración de forma que el for me dará errores, así que crearemos otro vector
    int longitud = v_pares.size();
    cout<<"El vector completo al reves es: [ ";
    for (int i = (longitud - 1); i >= 0; i--){
        v_final.push_back(v_pares.at(i));
        cout<<v_pares.at(i)<<" ";
        v_final.push_back(v_impares.at(i));
        cout<<v_impares.at(i)<<" ";
    }
    cout<<"]"<<endl<<endl;

    system("pause");
    return 0;

}

