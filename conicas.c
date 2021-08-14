#include <stdio.h>
#include <math.h>

#define N 6

void ingresar_datos(float D[N]);
int tipo_conica(int A, int C);

void datos_recta(float coeficiente[N]);
void datos_circunferencia(float coeficiente[N]);
void datos_elipse(float coeficiente[N]);
void datos_hiperbola(float coeficiente[N]);
void datos_parabola(float coeficiente[N]);

int main(void){

	float coeficiente[N]={0}; /*coeficienteicientes de la ecuacion general de la conica*/

   int op; 
   int salida=1;

	do
   {

   printf("Opciones:\n");
   printf("1- Introducir cónica\n");
   printf("2- Salir\n");
   
   scanf("%d", &op);

   switch(op)
   {
      case 1: 
      
      	printf("Introduzca los coeficiente la ecuacion general de la conica: \n");
      	printf("Ax^2 + Bxy + Cy^2 + Dx + Ey + F = 0 \n\n");

	      ingresar_datos(coeficiente);
   
         if(coeficiente[1] != 0)
         {  
            printf("\nEl coeficiente B nos determina la rotación que tendrá la cónica respecto a los ejes de coordenadas\n");
            printf("Este procedimiento no es visto por la cátedra de Álgebra y Geometría Analítica, por lo tanto lo to-\n");
            printf("mamos como B=0\n\n");
            coeficiente[1]=0;
          }

   	   switch(tipo_conica(coeficiente[0],coeficiente[2]))
         {

	          case 0:
			       if(coeficiente[3]==0 && coeficiente[4]==0 && coeficiente[5]!=0)/*Todos los terminos 0*/
				   	{ 
					   	printf("\t\nFuncion Incompatible");
					   	break;   
				   	}	 
			      	else if(coeficiente[3]==0 && coeficiente[4]==0 && coeficiente[5]==0) /*Funcion incompatible*/
				      {
					   	printf("\t\nPlano coordenado xy");
						   break;   
			   		}
				
			      	printf("\t\nRecta\n");
			      	datos_recta(coeficiente);
			      	break;

		       case 1:
			       printf("\t\nCircunferencia\n");
			       datos_circunferencia(coeficiente);
			       break;

		       case 2:
			   	printf("\t\nElipse\n");
			   	datos_elipse(coeficiente);
			   	break;

		       case 3:
			   	printf("\t\nHiperbola\n");
			   	datos_hiperbola(coeficiente);
			   	break;

		       case 4:
			      printf("\t\nParabola\n");
				   datos_parabola(coeficiente);
			   	break;
	       }
      break;

      case 2:
         salida=0;
         printf("\nPrograma creado por:\n");
         printf("\n   Chirino, Juan\n   Manolucos, Enzo\n   Martínez, Rubén\n   Luraschi, Nicolás\n   Villegas, Sebastián\n\n");
      
         printf("UTN - Ingeniería Electrónica 2016\n");
         
         break;

      case 666:
         printf("Six, six, six! The number of the beast!\n");
         printf("________666666666666666________\n"); 
         printf("______66666_________66666______\n"); 
         printf(" ____666_6_____________6__666___\n");
         printf(" ___666__666_________666___666__\n"); 
         printf(" _666_____6666_____6666____666__\n"); 
         printf(" 666_______6__66666__66______666 \n");
         printf(" 66________66_66666__6________66\n"); 
         printf(" 66________666____6666________66\n"); 
         printf(" 66______6666______66666______66\n");
         printf(" 66____66___66_____66____66___66\n");
         printf(" 66_6666666666666666666666666_66\n"); 
         printf(" 666_________66___6___________66\n"); 
         printf(" _666_________6__66_________666_\n"); 
         printf(" __666________6666_________666__\n"); 
         printf(" ____666_______666_______666____\n"); 
         printf(" ______66666____6_____6666______\n"); 
         printf(" _________6666666666666_________\n");
        
          break;

      default:
         printf("Opcion incorrecta, es 1 y 2. No es muy complicado\n");
         break;
      }
		printf("\n\n");

	}while(salida==1);

	return 0;
}


void ingresar_datos(float D[N])
{
	int i;

	for(i=0;i<6;i++)
	{
		 printf("Ingrese el coeficiente %c: ",i+'A');
		 scanf("%f", &D[i]);
	}
}

int tipo_conica(int A, int C)
{
		int tipo;

		if(A==0 && C==0)
		{
			 tipo=0; /*Recta*/
		}
		else
		{
			tipo=4; /*//parabola*/

			if((A*C)>0)
			{
				if(A==C)
				{
					tipo=1;    /*//circulo*/
				}else
				{
					tipo=2;    /*//elipse*/
				}
			}else if( (A*C)<0 )
			{
				tipo=3;    /*//hiperbola*/
			}
		}

	return tipo;
}

void datos_recta(float coeficiente[N]) /* Listo */
{
	float m,b;

	if(coeficiente[3]==0) /*paralelo al eje X*/
	 {
	 	if(coeficiente[5]==0)
			printf("La recta coincide con el eje x");
		 else
		 {
			printf("Cortes (x;y): \n");
			printf("\t(0.00 ; %.2f)", (-coeficiente[5])/coeficiente[4]);
		 }
	}
	else
	{
    	if(coeficiente[4]==0)
		{    /*paralelo al eje Y*/
				if(coeficiente[5]==0)
				{
                printf("La recta coincide con el eje y");
				}else
				{
                printf("Cortes (x;y): \n");
				printf("\t(%.2f ; 0.00)", (-coeficiente[5])/coeficiente[3]);
           		 }
		 }
        
		 else 
		 {
                printf("Cortes:\n");
				m=(-coeficiente[3])/coeficiente[4];
                b=(-coeficiente[5]/coeficiente[4]);
				printf("\tPunto 1: (x;y): (%.2f;0.00)\n",(-b/m));
                printf("\tPunto 2: (0.00;%.2f)\n",(b));
        }
	}
}

void datos_circunferencia(float coeficiente[N]) /* Listo */
{

	float h,k;	//coordenadas del centro
	float det;
   float x;

	det=pow(coeficiente[3],2)+pow(coeficiente[4],2)-4*coeficiente[5]; //determinante de la circunferencia

	h=-coeficiente[3]/(2*coeficiente[0]);	//centro en x
	k=-coeficiente[4]/(2*coeficiente[2]);	//centro en y

   x=(-1*coeficiente[5]/coeficiente[0]);

   printf("Centro(x;y):\t(%.2f ; %.2f)\n",h,k);

	if(det<0)
		printf("Radio:\t\t %.2fi",sqrt(-det)/2); //radio imaginario
	else
		printf("Radio:\t\t %.2f",sqrt(pow(h,2)+pow(k,2)+x));	//radio real

}

void datos_elipse(float coef[N]) /* Listo */
{

	float h,k; //coordenadas del centro
	float a,b,c; //ejes
   int i;

	for(i = 0; i < N; i++)
		coef[i]/=coef[5];

	if(coef[0]<0) //cambio de signo
		for(i=0;i<N;i++)
			coef[i]=-coef[i];


	if(coef[0]>coef[2])
	{ 						//elipse a eje vertical
		a=sqrt(coef[0]);
		b=sqrt(coef[2]);
		c=sqrt(pow(a,2)-pow(b,2));

		h=-coef[3]/(2*coef[0]);
		k=-coef[4]/(2*coef[2]);

		printf("Centro(x;y):\t(%.2f ; %.2f)\n",h,k);
		printf("Foco 1(x;y):\t(%.2f ; %.2f)\n",h,k+c);
		printf("Foco 2(x;y):\t(%.2f ; %.2f)\n",h,k-c);
		printf("Vertice 1(x;y):\t(%.2f ; %.2f)\n",h+b,k);
		printf("Vertice 2(x;y):\t(%.2f ; %.2f)\n",h,k+a);
      printf("Vertice 3(x;y):\t(%.2f ; %.2f)\n",h-b,k);
		printf("Vertice 4(x;y):\t(%.2f ; %.2f)\n",h,k-a);
	}
	else
	{ //elipse a eje horizontal
		a=sqrt(coef[2]);
		b=sqrt(coef[0]);
		c=sqrt(pow(a,2)-pow(b,2));

		h=-coef[3]/(2*coef[2]);
		k=-coef[4]/(2*coef[0]);

		printf("Centro(x;y):\t(%.2f ; %.2f)\n",h,k);
		printf("Foco 1(x;y):\t(%.2f ; %.2f)\n",h+c,k);
		printf("Foco 2(x;y):\t(%.2f ; %.2f)\n",h-c,k);
		printf("Vertice 1(x;y):\t(%.2f ; %.2f)\n",h+a,k);
		printf("Vertice 2(x;y):\t(%.2f ; %.2f)\n",h,k+b);
		printf("Vertice 3(x;y):\t(%.2f ; %.2f)\n",h-a,k);
		printf("Vertice 4(x;y):\t(%.2f ; %.2f)\n",h,k-b);

	}	
	}

void datos_hiperbola(float coeficiente[N]) /* Listo */
{
	float a;
	float b;
	float c;
	float h;
	float k;

   h=-1*(coeficiente[3]/(2*coeficiente[0]));
   
   k=-1*(coeficiente[4]/(2*coeficiente[2]));

	a =(1/(coeficiente[0]/((pow(coeficiente[3],2)/(4*(coeficiente[0])))+(pow(coeficiente[4],2)/(4*(coeficiente[2])))-coeficiente[5]))); 

	b =(1/(coeficiente[2]/((pow(coeficiente[3],2)/(4*(coeficiente[0])))+(pow(coeficiente[4],2)/(4*(coeficiente[2])))-coeficiente[5]))); 
   
   if(coeficiente[0]>coeficiente[2])
   {
      a=sqrt(a);
      b*=-1;
      b=sqrt(b);
      c = sqrt(a*a + b*b);

   	printf("Vertice 1 (x;y):\t(%.2f ; %.2f)\n",h+a,k);
   	printf("Vertice 2 (x;y):\t(%.2f ; %.2f)\n",h-a,k);
   	printf("Foco 1 (x;y):\t(%.2f ; %.2f)\n", c+h,k);
   	printf("Foco 2 (x;y):\t(%.2f ; %.2f)\n", h-c,k);

   }
   else if(coeficiente[2]>coeficiente[0])
   {
      a*=-1;
      a=sqrt(a);
      b=sqrt(b);
      c = sqrt(a*a + b*b);
  
   	printf("Vertice 1 (x;y):\t(%.2f ; %.2f)\n",h,k+b);
   	printf("Vertice 2 (x;y):\t(%.2f ; %.2f)\n",h,k-b);
   	printf("Foco 1 (x;y):\t(%.2f ; %.2f)\n", h,k+c);
   	printf("Foco 2 (x;y):\t(%.2f ; %.2f)\n", h,k-c);
   
   }
   printf("Asintota 1: y%.2f= %.f(x%.2f)\n", k, b/a, h);
   printf("Asintota 2: y%.2f=-%.f(x%.2f)\n", k, b/a, h);

}
void datos_parabola(float coeficiente[N])
{
	float c;
   float h;
   float k;
	float raiz_positiva;
	float raiz_negativa;

	if (coeficiente[2]==0)/*parabola a eje y*/
		{	
			if(coeficiente[4]==0) /* Listo */
			{
				printf("Dos rectas paralelas al eje y\n");
				raiz_positiva =(-coeficiente[3] + sqrt(coeficiente[3]*coeficiente[3] - 4 * coeficiente[0]*coeficiente[5]))/(2*coeficiente[0]);
				
				raiz_negativa =(-coeficiente[3] - sqrt(coeficiente[3]*coeficiente[3] - 4 * coeficiente[0]*coeficiente[5]))/(2*coeficiente[0]);
				printf("Las rectas estan en x_1 = %.2f, x_2 = %.2f",raiz_positiva, raiz_negativa);
				
			}
			if(coeficiente[4]!=0)
			{
               h=-1*(coeficiente[3]/(2*coeficiente[0]));
               k=-1*((-coeficiente[5]+(pow(coeficiente[3],2)/(4*coeficiente[0])))/(-coeficiente[4]));
               /*c=1/(4*coeficiente[0])/(-coeficiente[4]);*/
               c=((-coeficiente[4])/(4*coeficiente[0]));
               printf("c: %f\n", c);
               printf("k: %f\n", k);

					printf("Vertice: (%.3f, %.3f)\n", h, k);
               printf("Directriz: y=%.3f\n",k-c);
               printf("Foco: (%.3f, %.3f)\n", h,c+k);
               printf("Eje focal: x=%.3f\n", h);
                         
			}	
		}

	if (coeficiente[0]==0)/*parabola a eje x*/
		{	
			if(coeficiente[3]==0) /* Listo */
			{
				printf("Dos rectas paralelas al eje x\n");
			
				raiz_positiva =(-coeficiente[4] + sqrt(coeficiente[4]*coeficiente[4] - 4 * coeficiente[2]*coeficiente[5]))/(2*coeficiente[2]);
				raiz_negativa =(-coeficiente[4] - sqrt(coeficiente[4]*coeficiente[4] - 4 * coeficiente[2]*coeficiente[5]))/(2*coeficiente[2]);
				printf("Las rectas estan en y_1 = %.2f, y_2 = %.2f",raiz_positiva, raiz_negativa);
					
			}
			if(coeficiente [3] != 0)
			{
        
               h=-1*(coeficiente[4]/(2*coeficiente[2]));
               k=-1*((-coeficiente[5]+(pow(coeficiente[4],2)/(4*coeficiente[2])))/(-coeficiente[3]));
               /*c=1/(4*coeficiente[0])/(-coeficiente[4]);*/
               c=((-coeficiente[3])/(4*coeficiente[2]));
               printf("c: %f\n", c);
               printf("k: %f\n", k);

               printf("h: %f\n", h);
					printf("Vertice: (%.3f, %.3f)\n", k, h); /*Diste vuelta el h y k */
               printf("Directriz: x=%.3f\n",k-c); /* h -c */
               printf("Foco: (%.3f, %.3f)\n", k+c,h); /* h+c, k */
               printf("Eje focal: y=%.3f\n", h);
            
			}
		}
}		
