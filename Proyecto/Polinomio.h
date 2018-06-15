/** Polinomio.h - Clase para realizar operaciones aritméticas
 *  con polinomios que tienen coeficientes racionales:
 *  suma de polinomios, resta de polinomios, multiplicación 
 *  de polinomios y división de polinomios.
 *  @version 2017.09.15
 */
struct Rac;       /* declaración anticipada */ 
struct Polinomio{
  int grado;    //Grado del polinomio
  Rac *A;       //coeficientes del polinomio
//  char nombre[40];  	//nombre de la varible
  Polinomio& operator+(Polinomio& PolObj);
  Polinomio& operator-(Polinomio& PolObj);
  Polinomio& operator*(Polinomio& PolObj);
  Polinomio& operator/(Polinomio& PolObj);
  friend ostream& 
  operator<<(ostream& ostreamOut,Polinomio& PolObj); 
  /* constructor(es) */
  /*
   * @param RacPt: debe apuntar a intGrado+1 objetos de 
   * clase Rac.
   * @param intGrado: debe ser el grado del polinomio.
   */
  Polinomio(int intGrado,Rac *RacPt);
	void ImpPol();
  Polinomio();
};//end class Polinomio


