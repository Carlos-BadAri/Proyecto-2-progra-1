#include "Menu.h"
#include <fstream>
using namespace std;

Menu::Menu() : lsSucursales(NULL),lsClientes(NULL),lsColabs(NULL),lsPlanteles(NULL),lsVehiculos(NULL),lsSolicitudes(NULL),lsContratos(NULL),arcSuc("sucursales.txt"),arcCli(),arcCol("colaboradores.txt"),arcPla("planteles.txt"),arcVeh(),arcSol("solicitudes.txt"),arcCon("contratos.txt"){
        // No cargamos archivos porque no hay listas enlazadas todavía

}
Menu::Menu(ListaSucursal* s, ListaCliente* c, ListaColaborador* co,ListaPlantel* p, ListaVehiculo* v, ListaSolicitud* so, ListaContrato* cn) : lsSucursales(s), lsClientes(c), lsColabs(co), lsPlanteles(p), lsVehiculos(v), lsSolicitudes(so), lsContratos(cn),arcSuc("sucursales.txt"),arcCli(),arcCol("colaboradores.txt"),arcPla("planteles.txt"),arcVeh(), arcSol("solicitudes.txt"),arcCon("contratos.txt"){
    // Cargar solo si el archivo existe
    { ifstream f("sucursales.txt");  
    if (f) arcSuc.cargar(lsSucursales); 
    }
    { ifstream f("clientes.txt");   
    if (f) arcCli.cargar(lsClientes);
    }
    { ifstream f("colaboradores.txt"); 
    if (f) arcCol.cargar(lsColabs);
    }
    { ifstream f("planteles.txt");   
    if (f) arcPla.cargar(lsPlanteles);
    }
    { ifstream f("vehiculos.txt");   
    if (f) arcVeh.cargar(lsVehiculos);
    }
    { ifstream f("solicitudes.txt");  
    if (f) arcSol.cargar(lsSolicitudes); 
    }
    { ifstream f("contratos.txt");   
    if (f) arcCon.cargar(lsContratos);
    }
}

Menu::~Menu() {
    arcSuc.guardar(lsSucursales);
    arcCli.guardar(lsClientes);
    arcCol.guardar(lsColabs);
    arcPla.guardar(lsPlanteles);
    arcVeh.guardar(lsVehiculos);
    arcSol.guardar(lsSolicitudes);
    arcCon.guardar(lsContratos);
}

void Menu::run() {
    bool salir = false;
    while (!salir) {
        menuPrincipal();
        int op = leerIntRango("Opción: ", 0, 6);
        switch (op) {
        case 1: datosGenerales(); break;
        case 2: menuPlantelesVehiculos(); break;
        case 3: menuSolicitudesContratos(); break;
        case 4: menuReportesCliente(); break;
        case 5: menuReportesPlantelVehiculos(); break;
        case 6: menuReportesAlquileres(); break;
        case 0: salir = true; break;
        default: break;
        }
    }
}

void Menu::menuPrincipal() {
    cout << "===== SISTEMA DE ALQUILER — MENÚ PRINCIPAL =====" << endl;
    cout << "1) Datos Generales" << endl;
    cout << "2) Planteles, Parqueos y Vehículos" << endl;
    cout << "3) Solicitudes y Contratos" << endl;
    cout << "4) Reportes de Cliente" << endl;
    cout << "5) Reportes de Planteles y Vehículos" << endl;
    cout << "6) Reportes de Alquileres" << endl;
    cout << "0) Salir" << endl;
}

int Menu::leerInt(const string& msg) {
    // Usa .size(), .empty(), .erase() y getline con validación simple
    string line;
    int value;
    bool valido = false;

    while (!valido) {
        cout << msg;
        getline(cin, line);

        while (!line.empty() && (line[0] == ' ' || line[0] == '\t')) {
            line.erase(0, 1);
        }
        while (!line.empty() && (line[line.size() - 1] == ' ' || line[line.size() - 1] == '\t')) {
            line.erase(line.size() - 1, 1);
        }

        if (line.empty()) {
            cout << "Debe ingresar un numero." << endl;
            continue;
        }

        bool esNumero = true;
        int i = 0;
        if (line[0] == '+' || line[0] == '-') i = 1;

        for (; i < (int)line.size(); i++) {
            if (line[i] < '0' || line[i] > '9') {
                esNumero = false;
                break;
            }
        }

        if (!esNumero) {
            cout << "Entrada invalida, digite un numero." << endl;
            continue;
        }

        stringstream ss(line);
        ss >> value;
        if (ss.fail()) {
            cout << "Error convirtiendo numero. Intente de nuevo." << endl;
            continue;
        }
        valido = true;
    }

    return value;
}

int Menu::leerIntRango(const string& msj, int minV, int maxV) {
    while (true) {
        int v = leerInt(msj);
        if (v < minV || v > maxV) {
            cout << "Valor fuera de rango [" << minV << ", " << maxV << "]" << endl;
            continue;
        }
        return v;
    }
}

string Menu::leerLinea(const string& msj) {
    cout << msj;
    string s;
    getline(cin, s);
    return s;
}

void Menu::esperarEnter() {
    cout << endl << "(Enter para continuar)";
    string dummy;
    getline(cin, dummy);
}

void Menu::datosGenerales() {
    int op;
    do {
        cout << "--- Datos Generales ---" << endl;
        cout << "1) Sucursales (ingreso/eliminación/visualización)" << endl;
        cout << "2) Clientes por sucursal (ingreso/eliminación/visualización)" << endl;
        cout << "3) Colaboradores por sucursal (ingreso/eliminación/visualización)" << endl;
        cout << "0) Atrás" << endl;
        op = leerIntRango("Opción: ", 0, 3);
        switch (op) {
        case 1: {
            int opS;
            do {
                cout << "[Sucursales]" << endl;
                cout << "1) Ingresar" << endl;
                cout << "2) Eliminar" << endl;
                cout << "3) Ver" << endl;
                cout << "0) Atrás" << endl;
                opS = leerIntRango("Opción: ", 0, 3);
                if (opS == 1) crearSucursal();
                else if (opS == 2) eliminarSucursal();
                else if (opS == 3) verSucursales();
            } while (opS != 0);
        } break;
        case 2: {
            int opC;
            do {
                cout << "[Clientes]" << endl;
                cout << "1) Ingresar" << endl;
                cout << "2) Eliminar" << endl;
                cout << "3) Ver" << endl;
                cout << "0) Atrás" << endl;
                opC = leerIntRango("Opción: ", 0, 3);
                if (opC == 1) crearCliente();
                else if (opC == 2) eliminarCliente();
                else if (opC == 3) verClientes();
            } while (opC != 0);
        } break;
        case 3: {
            int opCo;
            do {
                cout << "[Colaboradores]" << endl;
                cout << "1) Ingresar" << endl;
                cout << "2) Eliminar" << endl;
                cout << "3) Ver" << endl;
                cout << "0) Atrás" << endl;
                opCo = leerIntRango("Opción: ", 0, 3);
                if (opCo == 1) crearColaborador();
                else if (opCo == 2) eliminarColaborador();
                else if (opCo == 3) verColaboradores();
            } while (opCo != 0);
        } break;
        default: break;
        }
    } while (op != 0);
}

void Menu::crearSucursal() {
    string cod = leerLinea("Código: ");
    string nom = leerLinea("Nombre: ");
    string dir = leerLinea("Dirección: ");
    string pais = leerLinea("País: ");
    Sucursal* s = new Sucursal(cod, nom, dir, pais);
    lsSucursales->insertarFinal(new NodoSucursal(s));
    cout << "Sucursal creada." << endl;
}

void Menu::eliminarSucursal() {
    cout << endl << "--- Eliminar Sucursal ---" << endl;

    string codigo;
    cout << "Digite el codigo de la sucursal a eliminar: ";
    getline(cin, codigo);

    Sucursal* suc = lsSucursales->buscar(codigo);

    if (suc == NULL) {
        cout << "No existe una sucursal con ese codigo." << endl;
        esperarEnter();
        return;
    }
    bool eliminado = lsSucursales->Eliminar(codigo);

    if (eliminado) {
        cout << "Sucursal eliminada correctamente." << endl;
    }
    else {
        cout << "No se pudo eliminar la sucursal." << endl;
    }

    esperarEnter();
}

void Menu::verSucursales() {
    cout << lsSucursales->toString();
    esperarEnter();
}

void Menu::crearCliente() {
    string id = leerLinea("ID cliente: ");
    string nom = leerLinea("Nombre: ");
    string pais = leerLinea("País residencia: ");
    lsClientes->agregar(new Cliente(id, nom, pais));
    cout << "✔ Cliente ingresado." << endl;
}

void Menu::eliminarCliente() {
    cout << "(No implementado: agregue eliminación en ListaCliente)" << endl;
}

void Menu::verClientes() {
    cout << lsClientes->toString();
    esperarEnter();
}

void Menu::crearColaborador() {
    string id = leerLinea("ID colaborador: ");
    string nom = leerLinea("Nombre: ");
    string puesto = leerLinea("Puesto: ");
    string suc = leerLinea("Sucursal asignada (código): ");
    lsColabs->agregar(new Colaborador(id, nom, puesto, suc));
    cout << "✔ Colaborador ingresado." << endl;
}

void Menu::eliminarColaborador() {
    cout << "(No implementado: agregue eliminación en ListaColaborador)" << endl;
}

void Menu::verColaboradores() {
    cout << lsColabs->toString();
    esperarEnter();
}

void Menu::menuPlantelesVehiculos() {
    int op;
    do {
        cout << "--- Planteles, Parqueos y Vehículos ---" << endl;
        cout << "1) Crear plantel (dibuja distribución)" << endl;
        cout << "2) Ingresar vehículo (con recomendación)" << endl;
        cout << "3) Eliminar vehículo" << endl;
        cout << "4) Ver vehículos" << endl;
        cout << "5) Reubicar vehículo en la misma sucursal" << endl;
        cout << "6) Visualizar distribución plantel y consultar placa por espacio" << endl;
        cout << "7) Cambiar estado de un vehículo (registra en bitácora)" << endl;
        cout << "8) Trasladar n vehículos de sucursal A a B" << endl;
        cout << "0) Atrás" << endl;
        op = leerIntRango("Opción: ", 0, 8);
        switch (op) {
        case 1: crearPlantel(); break;
        case 2: ingresarVehiculo(); break;
        case 3: eliminarVehiculo(); break;
        case 4: verVehiculos(); break;
        case 5: reubicarVehiculo(); break;
        case 6: verDistribucionPlantel(); break;
        case 7: cambiarEstadoVehiculo(); break;
        case 8: trasladarVehiculos(); break;
        default: break;
        }
    } while (op != 0);
}

void Menu::crearPlantel() {
    string sl = leerLinea("Letra del plantel (A-Z): ");
    char letra = sl.empty() ? 'A' : sl[0];
    int tipo = leerIntRango("Tipo (1=ligero,2=pesado,...): ", 1, 5);
    int f = leerIntRango("Filas: ", 1, 100);
    int c = leerIntRango("Columnas: ", 1, 100);

    Plantel* p = new Plantel(letra, tipo, f, c);
    lsPlanteles->insertarFinal(new NodoPlantel(p));

    cout << "Distribución de parqueos (D=Disponible, X=Ocupado)" << endl;
    dibujarMatriz(p);
    esperarEnter();
}

void Menu::verDistribucionPlantel() {
    Plantel* p = seleccionarPlantelPorLetra();
    if (!p) return;
    dibujarMatriz(p);

    string codigo = leerLinea("Digite código de espacio (e.g., A-1-3) para ver la placa o vacío para volver: ");
    if (codigo.empty()) return;

    EspacioEstacionamiento* e = buscarEspacioPorCodigo(p, codigo);
    if (!e) { cout << "No existe el espacio." << endl; return; }
    if (e->getVehiculo()) cout << "Placa: " << e->getVehiculo()->getPlaca() << endl;
    else cout << "Espacio disponible." << endl;
    esperarEnter();
}

void Menu::ingresarVehiculo() {
    string placa = leerLinea("Placa: ");
    string marca = leerLinea("Marca: ");
    string modelo = leerLinea("Modelo: ");
    string color = leerLinea("Color: ");
    int anio = leerIntRango("Año: ", 1900, 2100);

    Vehiculo* v = new Vehiculo(placa, marca, modelo, color, anio);

    Plantel* p = seleccionarPlantelPorLetra();
    if (!p) { delete v; return; }

    EspacioEstacionamiento* esp = recomendarEspacio(p);
    if (!esp) {
        cout << "No hay espacios disponibles en ese plantel." << endl;
        delete v;
        return;
    }
    esp->setVehiculo(v);
    esp->setEstado("Ocupado");
    lsVehiculos->insertarFinal(new NodoVehiculo(v));

    cout << "✔ Vehículo estacionado en " << esp->getCodigo() << endl;
}

void Menu::eliminarVehiculo() {
    cout << "(No implementado: complete eliminación en listas y libere el espacio)" << endl;
}

void Menu::verVehiculos() {
    cout << lsVehiculos->toString();
    esperarEnter();
}

void Menu::reubicarVehiculo() {
    cout << "(No implementado: busque vehículo por placa y mueva de un espacio a otro dentro del mismo plantel/sucursal)" << endl;
}

void Menu::cambiarEstadoVehiculo() {
    cout << "(No implementado: cambie el estado en Vehiculo->BitacoraEstado y agregue entrada: anterior, nuevo, fecha, colaborador)" << endl;
}

void Menu::trasladarVehiculos() {
    cout << "(No implementado: liste disponibles no alquilados y reubique n desde sucursal A a B según recomendaciones)" << endl;
}

void Menu::menuSolicitudesContratos() {
    int op;
    do {
        cout << "--- Solicitudes y Contratos ---" << endl;
        cout << "1) Crear solicitud" << endl;
        cout << "2) Ver solicitudes" << endl;
        cout << "3) Aprobar/Rechazar solicitud" << endl;
        cout << "4) Recepción de vehículo y finalización de contrato" << endl;
        cout << "0) Atrás" << endl;
        op = leerIntRango("Opción: ", 0, 4);
        if (op == 1) crearSolicitud();
        else if (op == 2) verSolicitudes();
        else if (op == 3) aprobarRechazarSolicitud();
        else if (op == 4) recibirYFinalizarContrato();
    } while (op != 0);
}

void Menu::crearSolicitud() {
    cout << "(No implementado: cree objeto SolicitudAlquiler con detalle y añádalo a lsSolicitudes)" << endl;
}

void Menu::verSolicitudes() {
    cout << lsSolicitudes->toString();
    esperarEnter();
}

void Menu::aprobarRechazarSolicitud() {
    cout << "(No implementado: cambie estado de Solicitud y, si aprueba, genere ContratoAlquiler)" << endl;
}

void Menu::recibirYFinalizarContrato() {
    cout << "(No implementado: marque devolución y cierre contrato)" << endl;
}

void Menu::menuReportesCliente() { menuReportesClienteImpl(); }
void Menu::menuReportesPlantelVehiculos() { menuReportesPlantelVehImpl(); }
void Menu::menuReportesAlquileres() { menuReportesAlquileresImpl(); }

void Menu::menuReportesClienteImpl() {
    int op;
    do {
        cout << "--- Reportes de Cliente ---" << endl;
        cout << "1) Historial del cliente" << endl;
        cout << "2) Clientes por cantidad de contratos" << endl;
        cout << "0) Atrás" << endl;
        op = leerIntRango("Opción: ", 0, 2);
        if (op == 1) reporteHistorialCliente();
        else if (op == 2) reporteClientesPorContratos();
    } while (op != 0);
}

void Menu::menuReportesPlantelVehImpl() {
    int op;
    do {
        cout << "--- Reportes de Planteles y Vehículos ---" << endl;
        cout << "1) Estados de un vehículo (bitácora)" << endl;
        cout << "2) Contratos por vehículo" << endl;
        cout << "3) % de ocupación de planteles" << endl;
        cout << "0) Atrás" << endl;
        op = leerIntRango("Opción: ", 0, 3);
        if (op == 1) reporteEstadosVehiculo();
        else if (op == 2) reporteContratosPorVehiculo();
        else if (op == 3) reporteOcupacionPlanteles();
    } while (op != 0);
}

void Menu::menuReportesAlquileresImpl() {
    int op;
    do {
        cout << "--- Reportes de Alquileres ---" << endl;
        cout << "1) Contratos por sucursal (reciente -> antiguo)" << endl;
        cout << "2) Reporte de alquileres por colaborador" << endl;
        cout << "0) Atrás" << endl;
        op = leerIntRango("Opción: ", 0, 2);
        if (op == 1) verContratosPorSucursal();
        else if (op == 2) reporteAlquileresPorColaborador();
    } while (op != 0);
}

void Menu::reporteHistorialCliente() {
    cout << "(No implementado: listar solicitudes y contratos por ID cliente)" << endl;
}
void Menu::reporteClientesPorContratos() {
    cout << "(No implementado: ordenar clientes por cantidad de contratos)" << endl;
}
void Menu::reporteEstadosVehiculo() {
    cout << "(No implementado: imprimir bitácora de cambios de un vehículo)" << endl;
}
void Menu::reporteContratosPorVehiculo() {
    cout << "(No implementado: listar contratos de un vehículo)" << endl;
}
void Menu::reporteOcupacionPlanteles() {
    cout << "(No implementado: calcular % ocupación = ocupados/total por sucursal)" << endl;
}
void Menu::verContratosPorSucursal() {
    cout << "(No implementado: ordenar contratos por fecha desc y mostrar detalle)" << endl;
}
void Menu::reporteAlquileresPorColaborador() {
    cout << "(No implementado: filtrar contratos por colaborador)" << endl;
}

Sucursal* Menu::seleccionarSucursalPorCodigo(const string& prompt) {
    string cod = leerLinea(prompt);
    return lsSucursales->buscar(cod);
}

Plantel* Menu::seleccionarPlantelPorLetra() {
    string sl = leerLinea("Letra de plantel: ");
    char letra = sl.empty() ? 'A' : sl[0];

    for (NodoPlantel* n = lsPlanteles->getPpio(); n; n = n->getSiguiente()) {
        if (n->getDato()->getLetra() == letra) return n->getDato();
    }
    cout << "No se encontró plantel." << endl;
    return 0;
}

EspacioEstacionamiento* Menu::recomendarEspacio(Plantel* p) {
    if (!p) return 0;
    EspacioEstacionamiento** m = p->getMatriz();
    if (!m) return 0;

    for (int i = 0; i < p->getFilas(); ++i) {
        for (int j = 0; j < p->getColumnas(); ++j) {
            EspacioEstacionamiento* e = &m[i][j];
            if (e->getEstado() == "Disponible" && e->getVehiculo() == 0) {
                return e;
            }
        }
    }
    return 0;
}

EspacioEstacionamiento* Menu::buscarEspacioPorCodigo(Plantel* p, const string& codigoEsp) {
    if (!p) return 0;
    EspacioEstacionamiento** m = p->getMatriz();
    if (!m) return 0;

    for (int i = 0; i < p->getFilas(); ++i) {
        for (int j = 0; j < p->getColumnas(); ++j) {
            if (m[i][j].getCodigo() == codigoEsp) return &m[i][j];
        }
    }
    return 0;
}

void Menu::dibujarMatriz(Plantel* p) {
    if (!p) return;
    EspacioEstacionamiento** m = p->getMatriz();
    int F = p->getFilas(), C = p->getColumnas();

    cout << "   ";
    for (int j = 0; j < C; ++j) {
        cout << j;
        if (j + 1 < C) cout << " ";
    }
    cout << endl;
    for (int i = 0; i < F; ++i) {
        cout << char('A' + i) << ": ";
        for (int j = 0; j < C; ++j) {
            char ch = 'D'; // Disponible
            if (m && m[i][j].getEstado() == string("Ocupado")) ch = 'X';
            cout << ch;
            if (j + 1 < C) cout << " ";
        }
        cout << endl;
    }
}
