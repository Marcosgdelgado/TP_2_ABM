typedef struct
{
    int legajo;
    char nombre[51];
    char apellido[51];
    char sexo;
    float sueldo;
    int idSector;
    int isEmpty;
} eEmpleado;

typedef struct
{
    int id;
    char descripcion[20];
} eSector;

/** \brief Lista los sectores a elegir
 * \param recibe lista
 * \return imprime
 */
void listarSectores(eSector[], int);

/** \brief Obtiene sector seleccionado
 * \param
 * \return almacena sector en array
 */
void obtenerSector(eSector[], int , int, char[]);
/** \brief Busca el empleado por id
 * \param emp* puntero al array de empleados
 * \param CANT Entero del total del array
 * \param id int auxiliar, id a ser buscado en el array
 * \return int Retorna (-1) si hay error o si el id no se encontro,
 * la posicion del array si no hay error.
 */
void inicializarEmpleados(eEmpleado[], int);

void mostrarEmpleado(eEmpleado, eSector[], int);

int buscarLibre(eEmpleado[], int);

int buscarEmpleado(eEmpleado [], int, int);

void altaEmpleado(eEmpleado [], int, eSector[], int);

void bajaEmpleado(eEmpleado [], int, eSector[], int);

void ModificarEmpleado(eEmpleado [], int, eSector[], int);

void ordenarEmpleadosXlegajo(eEmpleado [], int);

void harcodearEmpleados(eEmpleado empleados[]);

void mostrarEmpleados(eEmpleado [], int, eSector[], int);

void listarEmpleadosXSector(eEmpleado [],int, eSector[], int);

void ordenarXSectorYNombre(eEmpleado [],int, eSector[], int);

void mostrarEmpleadosMasGanadores(eEmpleado [],int, eSector[], int);

int menu();
void cargarSectores(eSector[]);


