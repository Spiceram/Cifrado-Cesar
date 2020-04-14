#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Cifrado_Cesar
{

public:
  string cifrado(string mensaje);
  string descifrado(string mensajecifrado);
  Cifrado_Cesar();

private:
  string alf;
  int clave = 3; //--------> Volvemos privada 
  int indice;

};// (;)

Cifrado_Cesar::Cifrado_Cesar()
{

  alf = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";//---------->Alfabeto Estandar 
 
};


string Cifrado_Cesar::cifrado(string M)//------->Cifrador 
{

  for (int i = 0; i < M.length(); i++)
  {

    if (isalpha(M[i]))
    {

      indice = alf.find(M[i]);
      if(islower(M[i]))
      {

        if(indice + clave >= 26)
        {
          M[i] = alf[(indice + clave) - 26];
        }

        else
        {
          M[i] = alf[indice + clave];
        }

      }

      else
      {

        if(indice + clave >= alf.length())
        {
          M[i] = alf[(indice + clave) - 26];
        }
        else
        {
          M[i] = alf[indice + clave];
        }

      }
    }
  }
  return M;
};

string Cifrado_Cesar::descifrado(string Mcifrado)//------->Descifrador
{

  for (int i = 0; i < Mcifrado.length(); i++)
  {

    if (isalpha(Mcifrado[i]))
    {

      indice = alf.find(Mcifrado[i]);
      if(islower(Mcifrado[i]))
      {

        if(indice - clave < 0)
        {
          Mcifrado[i] = alf[(indice - clave) + 26];
        }

        else
        {
          Mcifrado[i] = alf[indice - clave];
        }

      }

      else
      {

        if(indice - clave < 26)
        {
          Mcifrado[i] = alf[(indice - clave) + 26];
        }
        else
        {
          Mcifrado[i] = alf[indice - clave];
        }

      }
    }
  }
return Mcifrado;
};
