//Roberto Carlos de León Gramajo
//5090-23-1762
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Trabajador {
private:
    struct Empleado {
        string nombre;
        string Segnombre;
        string apellido;
        string Segapellido;
        int edad;
        bool Sexo;
        double salario;
        string horarioTrabajo;
    } Personal;

public:
    void obtenerDatosPersona() {
        cout << "\nDatos del Personal\n";
        cout << "Ingrese su primer nombre: ";
        cin >> Personal.nombre;
        cout << "Ingrese su segundo nombre: ";
        cin >> Personal.Segnombre;
        cout << "Ingrese su primer apellido: ";
        cin >> Personal.apellido;
        cout << "Ingrese su segundo apellido: ";
        cin >> Personal.Segapellido;
        cout << "Ingrese su edad: ";
        cin >> Personal.edad;
        cout << "¿Tipo de sexo? (1: Masculino / 0: Femenino): ";
        cin >> Personal.Sexo;
        cout << "¿Qué salario tiene?: Q";
        cin >> Personal.salario;
        cout << "1ra. Lunes, Miercoles y Viernes de 06:00 a.m. a 18:00 p.m., Martes y Jueves de 08:30 a.m. a 19:00 p.m.\n";
        cout << "2da. Lunes, Miercoles y Viernes de 07:00 a.m. a 19:00 p.m., Martes y Jueves de 07:00 a.m. a 18:00 p.m.\n";
        cout << "Elija un horario de clases (1 o 2): ";
        int opcion;
        cin >> opcion;
        Personal.horarioTrabajo = (opcion == 1) ? "Lunes, Miercoles y Viernes de 06:00 a.m. a 18:00 p.m., Martes y Jueves de 08:30 a.m. a 19:00 p.m.\n"
                                      : "Lunes, Miercoles y Viernes de 07:00 a.m. a 19:00 p.m., Martes y Jueves de 07:00 a.m. a 18:00 p.m.\n";
    }

    void guardarDatosEnArchivo(ofstream &archivo) {
        archivo << "Primer Nombre: " << Personal.nombre << endl;
        archivo << "Segundo Nombre: " << Personal.Segnombre << endl;
        archivo << "Primer Apellido: " << Personal.apellido << endl;
        archivo << "Segundo Apellido: " << Personal.Segapellido << endl;
        archivo << "Edad: " << Personal.edad << endl;
        archivo << "Tipo de sexo: " << (Personal.Sexo ? "Masculino" : "Femenino") << endl;
        archivo << "El salario de la persona es: Q" << Personal.salario << endl;
        archivo << "Horario del Trabajador: " << Personal.horarioTrabajo << endl;
    }
};

void leerDatosDesdeArchivo() {
    ifstream archivo("Empleado.txt");
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    archivo.close();
}

void eliminarDatosDeArchivo() {
    ofstream archivo("Empleado.txt", ios::trunc);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    cout << "Todos los datos del archivo 'Empleado.txt' han sido eliminados." << endl;

    archivo.close();
}

int main() {
    Trabajador trabajador; 

    int opcion;
    do {
        cout << "\nParcial 2:" << endl;
        cout << "1. Leer datos desde el archivo" << endl;
        cout << "2. Agregar trabajador" << endl;
        cout << "3. Eliminar todos los trabajadores" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                system("cls");
                leerDatosDesdeArchivo();
                break;
            case 2: {
                system("cls");
                ofstream archivo("Empleado.txt", ios::app);
                if (!archivo.is_open()) {
                    cout << "Error al abrir el archivo." << endl;
                    break;
                }
                trabajador.obtenerDatosPersona(); 
                trabajador.guardarDatosEnArchivo(archivo);
                archivo.close();
                cout << "Datos agregados correctamente." << endl;
                break;
            }
            case 3:
                system("cls");
                eliminarDatosDeArchivo();
                break;
            case 4:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción inválida. Inténtelo de nuevo." << endl;
        }
    } while (opcion != 4);

    return 0;
}

