// jhoan camilo bonilla gamboa 
// edwin leonel baltan carabali 

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

// Definir la estructura de un producto 
struct Producto {
    int id;                    // ID del producto
    char nombre[30];           // Nombre del producto
    struct Producto *sig;      // Puntero al siguiente producto
};

// Punteros globales para manipular la lista
Producto *cab = NULL, *aux = NULL, *aux2 = NULL;

// Función para agregar un producto
void agregarProducto() {
    // Reserva memoria para un nuevo nodo
    aux = (Producto *)malloc(sizeof(Producto));

    if (aux == NULL) {
        cout << "Error: no se pudo asignar memoria." << endl;
        return;
    }

    // Solicitar al usuario los datos del producto
    cout << "Ingrese el ID del producto: ";
    cin >> aux->id;

    // Leer el nombre del producto (asegurándose de no exceder 30 caracteres)
    cout << "Ingrese el nombre del producto (máximo 30 caracteres): ";
    cin >> aux->nombre; // Lee hasta el primer espacio (sin usar getline)

    aux->sig = NULL; // El nuevo nodo apunta a NULL (fin de lista)

    // Si la lista está vacía, el nuevo producto será la cabeza
    if (cab == NULL) {
        cab = aux;
    } else {
        // Recorre la lista hasta el último nodo
        aux2 = cab;
        while (aux2->sig != NULL) {
            aux2 = aux2->sig;
        }
        // Enlaza el nuevo producto al final de la lista
        aux2->sig = aux;
    }

    cout << "Producto agregado correctamente." << endl;
}

// Función para mostrar todos los productos
void mostrarProductos() {
    if (cab == NULL) {
        cout << "No hay productos registrados." << endl;
        return;
    }

    for (aux = cab; aux != NULL; aux = aux->sig) {
        cout << "ID: " << aux->id << ", Nombre: " << aux->nombre << endl;
    }
}

// Función para buscar un producto por ID
void buscarProducto() {
    int idBuscado;
    cout << "Ingrese el ID del producto a buscar: ";
    cin >> idBuscado;

    for (aux = cab; aux != NULL; aux = aux->sig) {
        if (aux->id == idBuscado) {
            cout << "Producto encontrado: ID: " << aux->id << ", Nombre: " << aux->nombre << endl;
            return;
        }
    }

    cout << "Producto no encontrado." << endl;
}

// Función para eliminar un producto por ID
void eliminarProducto() {
    int idEliminar;
    cout << "Ingrese el ID del producto a eliminar: ";
    cin >> idEliminar;

    if (cab == NULL) {
        cout << "La lista está vacía. No se puede eliminar." << endl;
        return;
    }

    // Caso si el nodo a eliminar es la cabeza
    if (cab->id == idEliminar) {
        aux = cab;
        cab = cab->sig; // La cabeza apunta al siguiente producto
        free(aux);      // Libera la memoria del nodo eliminado
        cout << "Producto eliminado correctamente." << endl;
        return;
    }

    // Caso general: recorrer la lista para encontrar el nodo a eliminar
    aux2 = cab;
    while (aux2->sig != NULL && aux2->sig->id != idEliminar) {
        aux2 = aux2->sig;
    }

    // Si el producto no fue encontrado
    if (aux2->sig == NULL) {
        cout << "Producto no encontrado." << endl;
        return;
    }

    // Eliminar el nodo
    aux = aux2->sig;
    aux2->sig = aux->sig; // El nodo anterior apunta al siguiente del nodo a eliminar
    free(aux);            // Libera la memoria del nodo eliminado
    cout << "Producto eliminado correctamente." << endl;
}

// Función para contar los productos registrados
void contarProductos() {
    int contador = 0;
    for (aux = cab; aux != NULL; aux = aux->sig) {
        contador++;
    }
    cout << "Cantidad de productos registrados: " << contador << endl;
}

// Función para modificar el nombre de un producto dado un ID
void modificarProducto() {
    int idModificar;
    cout << "Ingrese el ID del producto a modificar: ";
    cin >> idModificar;

    for (aux = cab; aux != NULL; aux = aux->sig) {
        if (aux->id == idModificar) {
            cout << "Producto encontrado. Nombre actual: " << aux->nombre << endl;
            cout << "Ingrese el nuevo nombre: ";
            cin >> aux->nombre; // Lee hasta el primer espacio
            cout << "Nombre del producto modificado correctamente." << endl;
            return;
        }
    }

    cout << "Producto no encontrado." << endl;
}

// Función para liberar toda la memoria ocupada por la lista
void liberarMemoria() {
    aux = cab;
    while (aux != NULL) {
        aux2 = aux->sig; // Guarda el siguiente nodo
        free(aux);       // Libera el nodo actual
        aux = aux2;      // Avanza al siguiente nodo
    }
    cab = NULL; // Después de liberar, cabeza queda en NULL
    cout << "Memoria liberada correctamente." << endl;
}

// Función principal con menú de opciones
int main() {
    int opc;

    do {
        // Muestra el menú
        cout << "\n==== MENÚ ====\n";
        cout << "1. Agregar producto\n";
        cout << "2. Mostrar productos\n";
        cout << "3. Buscar producto\n";
        cout << "4. Eliminar producto\n";
        cout << "5. Contar productos\n";
        cout << "6. Modificar producto\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opc;

        switch (opc) {
            case 1:
                agregarProducto();
                break;
            case 2:
                mostrarProductos();
                break;
            case 3:
                buscarProducto();
                break;
            case 4:
                eliminarProducto();
                break;
            case 5:
                contarProductos();
                break;
            case 6:
                modificarProducto();
                break;
            case 7:
                liberarMemoria();
                cout << "¡negativo para mas tarde !" << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    } while (opc != 7);

    return 0;
}
