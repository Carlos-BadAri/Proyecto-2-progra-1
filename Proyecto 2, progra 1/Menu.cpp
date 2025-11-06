#include "Menu.h"
#include <fstream>
using namespace std;

Menu::Menu() : lsSucursales(new ListaSucursal()), lsClientes(new ListaCliente()), lsColabs(new ListaColaborador()), lsPlanteles(new ListaPlantel()), lsVehiculos(new ListaVehiculo()), lsSolicitudes(new ListaSolicitud()), lsContratos(new ListaContrato()), arcSuc("sucursales.txt"), arcCli(), arcCol("colaboradores.txt"), arcPla("planteles.txt"), arcVeh(), arcSol("solicitudes.txt"), arcCon("contratos.txt")
{

}
Menu::Menu(ListaSucursal* s, ListaCliente* c, ListaColaborador* co, ListaPlantel* p, ListaVehiculo* v, ListaSolicitud* so, ListaContrato* cn) : lsSucursales(s), lsClientes(c), lsColabs(co), lsPlanteles(p), lsVehiculos(v), lsSolicitudes(so), lsContratos(cn), arcSuc("sucursales.txt"), arcCli(), arcCol("colaboradores.txt"), arcPla("planteles.txt"), arcVeh(), arcSol("solicitudes.txt"), arcCon("contratos.txt") {

    {
        ifstream f("sucursales.txt");
        if (f) arcSuc.cargar(lsSucursales);
    }
    {
        ifstream f("clientes.txt");
        if (f) arcCli.cargar(lsClientes);
    }
    {
        ifstream f("colaboradores.txt");
        if (f) arcCol.cargar(lsColabs);
    }
    {
        ifstream f("planteles.txt");
        if (f) arcPla.cargar(lsPlanteles);
    }
    {
        ifstream f("vehiculos.txt");
        if (f) arcVeh.cargar(lsVehiculos);
    }
    {
        ifstream f("solicitudes.txt");
        if (f) arcSol.cargar(lsSolicitudes);
    }
    {
        ifstream f("contratos.txt");
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
        int op = leerIntRango("Opcion: ", 0, 6);
        switch (op) {
        case 1: datosGenerales();
            break;
        case 2: menuPlantelesVehiculos();
            break;
        case 3: menuSolicitudesContratos();
            break;
        case 4: menuReportesCliente(); 
            break;
        case 5: menuReportesPlantelVehiculos();
            break;
        case 6: menuReportesAlquileres();
            break;
        case 0: salir = true; 
            break;
        default:
            break;
        }
    }
}

void Menu::menuPrincipal() {
    cout << "SISTEMA DE ALQUILER — MENU PRINCIPAL" << endl;
    cout << "1) Datos Generales" << endl;
    cout << "2) Planteles, Parqueos y Vehiculos" << endl;
    cout << "3) Solicitudes y Contratos" << endl;
    cout << "4) Reportes de Cliente" << endl;
    cout << "5) Reportes de Planteles y Vehiculos" << endl;
    cout << "6) Reportes de Alquileres" << endl;
    cout << "0) Salir" << endl;
}

int Menu::leerInt(string msg) {
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

int Menu::leerIntRango(string msj, int minV, int maxV) {
    while (true) {
        int v = leerInt(msj);
        if (v < minV || v > maxV) {
            cout << "Valor fuera de rango [" << minV << ", " << maxV << "]" << endl;
            continue;
        }
        return v;
    }
}

string Menu::leerLinea(string msj) {
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
        cout << "Datos Generales" << endl;
        cout << "1) Sucursales (ingreso/eliminacion/visualizacion)" << endl;
        cout << "2) Clientes por sucursal (ingreso/eliminacion/visualizacion)" << endl;
        cout << "3) Colaboradores por sucursal (ingreso/eliminacion/visualizacion)" << endl;
        cout << "0) Atras" << endl;
        op = leerIntRango("Opcion: ", 0, 3);
        switch (op) {
        case 1: {
            int opS;
            do {
                cout << "Sucursales" << endl;
                cout << "1) Ingresar" << endl;
                cout << "2) Eliminar" << endl;
                cout << "3) Ver" << endl;
                cout << "0) Atras" << endl;
                opS = leerIntRango("Opcion: ", 0, 3);
                if (opS == 1) crearSucursal();
                else if (opS == 2) eliminarSucursal();
                else if (opS == 3) verSucursales();
            } while (opS != 0);
        } break;
        case 2: {
            int opC;
            do {
                cout << "Clientes" << endl;
                cout << "1) Ingresar" << endl;
                cout << "2) Eliminar" << endl;
                cout << "3) Ver" << endl;
                cout << "0) Atras" << endl;
                opC = leerIntRango("Opcion: ", 0, 3);
                if (opC == 1) crearCliente();
                else if (opC == 2) eliminarCliente();
                else if (opC == 3) verClientes();
            } while (opC != 0);
        } break;
        case 3: {
            int opCo;
            do {
                cout << "Colaboradores" << endl;
                cout << "1) Ingresar" << endl;
                cout << "2) Eliminar" << endl;
                cout << "3) Ver" << endl;
                cout << "0) Atras" << endl;
                opCo = leerIntRango("Opcion: ", 0, 3);
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
    string cod = leerLinea("Codigo: ");
    string nom = leerLinea("Nombre: ");
    string dir = leerLinea("Direccion: ");
    string pais = leerLinea("Pais: ");
    Sucursal* s = new Sucursal(cod, nom, dir, pais);
    lsSucursales->insertarFinal(new NodoSucursal(s));
    cout << "Sucursal creada." << endl;
}

void Menu::eliminarSucursal() {
    cout << endl << "Eliminar Sucursal" << endl;

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
    string pais = leerLinea("Pais residencia: ");
    lsClientes->agregar(new Cliente(id, nom, pais));
    cout << "Cliente ingresado." << endl;
}

void Menu::eliminarCliente() {
    cout << endl << "Eliminar Cliente" << endl;

    string id = leerLinea("Digite el id del cliente a eliminar: ");

    Cliente* cli = lsClientes->buscar(id);
    if (cli == NULL) {
        cout << "No existe un cliente con ese id." << endl;
        esperarEnter();
        return;
    }

    bool ok = lsClientes->eliminar(id);

    if (ok)
        cout << "Cliente eliminado correctamente." << endl;
    else
        cout << "No se pudo eliminar el cliente." << endl;

    esperarEnter();
}

void Menu::verClientes() {
    cout << lsClientes->toString();
    esperarEnter();
}

void Menu::crearColaborador() {
    string id = leerLinea("ID colaborador: ");
    string nom = leerLinea("Nombre: ");
    string puesto = leerLinea("Puesto: ");
    string suc = leerLinea("Sucursal asignada (codigo): ");
    lsColabs->agregar(new Colaborador(id, nom, puesto, suc));
    cout << "Colaborador ingresado." << endl;
}

void Menu::eliminarColaborador() {
    cout << endl << "Eliminar Colaborador" << endl;

    string id = leerLinea("Digite el id del colaborador a eliminar: ");

    Colaborador* col = lsColabs->buscar(id);
    if (col == NULL) {
        cout << "No existe un colaborador con ese id." << endl;
        esperarEnter();
        return;
    }

    bool ok = lsColabs->eliminar(id);

    if (ok)
        cout << "Colaborador eliminado correctamente." << endl;
    else
        cout << "No se pudo eliminar el colaborador." << endl;

    esperarEnter();
}


void Menu::verColaboradores() {
    cout << lsColabs->toString();
    esperarEnter();
}

void Menu::menuPlantelesVehiculos() {
    int op;
    do {
        cout << "Planteles, Parqueos y Vehiculos" << endl;
        cout << "1) Crear plantel (dibuja distribucion)" << endl;
        cout << "2) Ingresar vehiculo (con recomendacion)" << endl;
        cout << "3) Eliminar vehiculo" << endl;
        cout << "4) Ver vehiculos" << endl;
        cout << "5) Reubicar vehiculo en la misma sucursal" << endl;
        cout << "6) Visualizar distribucion plantel y consultar placa por espacio" << endl;
        cout << "7) Cambiar estado de un vehiculo (registra en bitacora)" << endl;
        cout << "8) Trasladar n vehiculos de sucursal A a B" << endl;
        cout << "0) Atras" << endl;
        op = leerIntRango("Opcion: ", 0, 8);
        switch (op) {
        case 1: crearPlantel();
            break;
        case 2: ingresarVehiculo(); 
            break;
        case 3: eliminarVehiculo();
            break;
        case 4: verVehiculos();
            break;
        case 5: reubicarVehiculo();
            break;
        case 6: verDistribucionPlantel();
            break;
        case 7: cambiarEstadoVehiculo();
            break;
        case 8: trasladarVehiculos();
            break;
        default: 
            break;
        }
    } while (op != 0);
}

void Menu::crearPlantel() {
    string sl = leerLinea("Letra del plantel (A-Z): ");
    char letra = sl.empty() ? 'A' : sl[0];
    int tipo = leerIntRango("Tipo (1=ligero,2=pesado,3=moto,4=electrico,5=especial): ", 1, 5);
    int f = leerIntRango("Filas: ", 1, 100);
    int c = leerIntRango("Columnas: ", 1, 100);

    Plantel* p = new Plantel(letra, tipo, f, c);
    lsPlanteles->insertarFinal(new NodoPlantel(p));

    cout << "Distribucion de parqueos (D=Disponible, X=Ocupado)" << endl;
    dibujarMatriz(p);
    esperarEnter();
}

void Menu::verDistribucionPlantel() {
    Plantel* p = seleccionarPlantelPorLetra();
    if (!p) return;
    dibujarMatriz(p);

    //Para que salga el espacio hay que usar la barra - y tambien es importante aclarar que las filas y columnas empiezan en 1, no en 0. asi si se ve que esta en la fila 0, el vehiculo esta en la posicion 1
    string codigo = leerLinea("Digite codigo de espacio (ejemplo:A-1-3) para ver la placa o vacio para volver: ");
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
    string estado = leerLinea("Estado(Disponible,Ocupado,Alquilado,Mantenimiento): ");
    int anio = leerIntRango("Ano: ", 1900, 2025);

    Vehiculo* v = new Vehiculo(placa, marca, modelo, color, anio, estado);

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

    cout << "Vehiculo estacionado en " << esp->getCodigo() << endl;
}

void Menu::eliminarVehiculo() {
    cout << endl << "Eliminar Vehiculo" << endl;

    string placa = leerLinea("Digite la placa del vehiculo a eliminar: ");

    Vehiculo* v = lsVehiculos->buscar(placa);
    if (v == NULL) {
        cout << "No existe un vehiculo con esa placa." << endl;
        esperarEnter();
        return;
    }
    bool eliminado = lsVehiculos->eliminar(placa);

    if (eliminado) {
        cout << "Vehiculo eliminado correctamente." << endl;

        NodoPlantel* aux = lsPlanteles->getPpio();
        while (aux != NULL) {
            Plantel* p = aux->getDato();
            EspacioEstacionamiento** m = p->getMatriz();

            for (int i = 0; i < p->getFilas(); i++) {
                for (int j = 0; j < p->getColumnas(); j++) {
                    EspacioEstacionamiento* e = &m[i][j];
                    if (e->getVehiculo() != NULL && e->getVehiculo()->getPlaca() == placa) {
                        e->setVehiculo(NULL);
                        e->setEstado("Disponible");
                        cout << "El espacio " << e->getCodigo() << " ha sido liberado." << endl;
                        break;
                    }
                }
            }
            aux = aux->getSiguiente();
        }
    }
    else {
        cout << "No se pudo eliminar el vehiculo." << endl;
    }

    esperarEnter();
}

void Menu::verVehiculos() {
    cout << lsVehiculos->toString();
    esperarEnter();
}

void Menu::reubicarVehiculo() {
    cout << endl << "Reubicar Vehiculo" << endl;
    string placa = leerLinea("Digite la placa del vehiculo a reubicar: ");

    Vehiculo* v = lsVehiculos->buscar(placa);
    if (v == NULL) {
        cout << "No existe un vehiculo con esa placa." << endl;
        esperarEnter();
        return;
    }

    Plantel* origenP = 0;
    EspacioEstacionamiento* origenE = 0;

    for (NodoPlantel* np = lsPlanteles->getPpio(); np != NULL && origenE == 0; np = np->getSiguiente()) {
        Plantel* p = np->getDato();
        EspacioEstacionamiento** m = p->getMatriz();
        if (!m) continue;

        for (int i = 0; i < p->getFilas() && origenE == 0; i++) {
            for (int j = 0; j < p->getColumnas(); j++) {
                EspacioEstacionamiento* e = &m[i][j];
                if (e->getVehiculo() != NULL && e->getVehiculo()->getPlaca() == placa) {
                    origenP = p;
                    origenE = e;
                    break;
                }
            }
        }
    }

    if (origenE == 0) {
        cout << "El vehiculo no esta estacionado en ningun plantel." << endl;
        esperarEnter();
        return;
    }

    string codigoOrigen = origenE->getCodigo();
    cout << "Ubicacion actual: " << codigoOrigen << " (Plantel " << origenP->getLetra() << ")" << endl;

    cout << "Distribucion del plantel actual:" << endl;
    dibujarMatriz(origenP);

    //Esto es lo mismo del metodo que esta mas arriba, se tiene que usar - y aunque la fila diga 0 la posicon es 1
    string codigoDestino = leerLinea("Digite codigo de espacio DESTINO (ej: A-1-3): ");
    EspacioEstacionamiento* destinoE = buscarEspacioPorCodigo(origenP, codigoDestino);

    if (destinoE == 0) {
        cout << "No existe el espacio destino." << endl;
        esperarEnter();
        return;
    }
    if (destinoE->getVehiculo() != 0) {
        cout << "El espacio destino esta ocupado." << endl;
        esperarEnter();
        return;
    }
    destinoE->setVehiculo(v);
    destinoE->setEstado("Ocupado");

    origenE->setVehiculo(0);
    origenE->setEstado("Disponible");

    cout << "Vehiculo reubicado de " << codigoOrigen << " a " << destinoE->getCodigo() << "." << endl;
    esperarEnter();
}


void Menu::cambiarEstadoVehiculo() {
    cout << endl << "Cambiar estado de vehiculo" << endl;

    string placa = leerLinea("Digite la placa del vehiculo: ");
    Vehiculo* v = lsVehiculos->buscar(placa);
    if (v == NULL) {
        cout << "No existe un vehiculo con esa placa." << endl;
        esperarEnter();
        return;
    }

    string estadoActual = v->getEstado();
    cout << "Estado actual: " << estadoActual << endl;

    cout << "Seleccione el nuevo estado:" << endl;
    cout << "  1) Disponible" << endl;
    cout << "  2) Ocupado" << endl;
    cout << "  3) Mantenimiento" << endl;
    cout << "  4) Alquilado" << endl;
    int op = leerIntRango("Opcion: ", 1, 4);

    string nuevoEstado;
    if (op == 1) nuevoEstado = "Disponible";
    else if (op == 2) nuevoEstado = "Ocupado";
    else if (op == 3) nuevoEstado = "Mantenimiento";
    else if (op == 4) nuevoEstado = "Alquilado";

    if (nuevoEstado == estadoActual) {
        cout << "El vehiculo ya se encuentra en el estado seleccionado." << endl;
        esperarEnter();
        return;
    }

    string idColab = leerLinea("ID del colaborador que realiza el cambio: ");
    Colaborador* col = lsColabs->buscar(idColab);
    if (col == NULL) {
        cout << "No existe un colaborador con ese ID." << endl;
        esperarEnter();
        return;
    }

    string fecha = leerLinea("Fecha del cambio (ej: 01-01-2025 14:30): ");

    v->setEstado(nuevoEstado);

    v->registrarCambioEstado(estadoActual, nuevoEstado, fecha, col->getId());

    cout << "Estado actualizado de '" << estadoActual << "' a '" << nuevoEstado << "'." << endl;
    cout << "Cambio registrado en la bitacora." << endl;

    esperarEnter();
}


void Menu::trasladarVehiculos() {
    cout << endl << "Trasladar vehiculos" << endl;

    int n = leerIntRango("Cantidad de vehiculos a trasladar: ", 1, 1000);

    string sucA = leerLinea("Codigo de sucursal origen: ");
    string sucB = leerLinea("Codigo de sucursal destino: ");

    int trasladados = 0;

    while (trasladados < n) {
        cout << endl << "[Traslado " << (trasladados + 1) << " de " << n << "]" << endl;

        string placa = leerLinea("Placa del vehiculo a trasladar: ");

        Vehiculo* v = lsVehiculos->buscar(placa);
        if (v == NULL) {
            cout << "No existe un vehiculo con esa placa." << endl;
            continue; // intenta el siguiente
        }

        if (v->getEstado() == "Alquilado") {
            cout << "El vehiculo tiene contrato activo (Alquilado). No se puede trasladar." << endl;
            continue;
        }

        Plantel* origenP = 0;
        EspacioEstacionamiento* origenE = 0;

        for (NodoPlantel* np = lsPlanteles->getPpio(); np != NULL && origenE == 0; np = np->getSiguiente()) {
            Plantel* p = np->getDato();
            EspacioEstacionamiento** m = p->getMatriz();
            if (!m) continue;

            for (int i = 0; i < p->getFilas() && origenE == 0; i++) {
                for (int j = 0; j < p->getColumnas(); j++) {
                    EspacioEstacionamiento* e = &m[i][j];
                    if (e->getVehiculo() != NULL && e->getVehiculo()->getPlaca() == placa) {
                        origenP = p;
                        origenE = e;
                        break;
                    }
                }
            }
        }

        if (origenE == 0) {
            cout << "Aviso: el vehiculo no aparece estacionado en ningun plantel (se trasladara igual al destino)." << endl;
        }
        else {
            cout << "Ubicacion actual: " << origenE->getCodigo()
                << " (Plantel " << origenP->getLetra() << ")" << endl;
        }

        cout << "Seleccione el plantel destino:" << endl;
        Plantel* destinoP = seleccionarPlantelPorLetra();
        if (!destinoP) {
            cout << "No se pudo seleccionar plantel destino." << endl;
            continue;
        }

        EspacioEstacionamiento* destinoE = recomendarEspacio(destinoP);
        if (!destinoE) {
            cout << "No hay espacios disponibles en el plantel destino." << endl;
            continue;
        }

        if (origenE != 0) {
            origenE->setVehiculo(0);
            origenE->setEstado("Disponible");
        }

        destinoE->setVehiculo(v);
        destinoE->setEstado("Ocupado");

        cout << "Traslado completado: placa " << placa
            << " -> " << destinoE->getCodigo()
            << " (Plantel " << destinoP->getLetra() << ")" << endl;
        v->setEstado("Ocupado");// Aqui lo dejo como "Ocupado" por estar en un espacio.

        trasladados++;
    }

    cout << endl << "Total trasladados: " << trasladados << " de " << n << "." << endl;
    esperarEnter();
}


void Menu::menuSolicitudesContratos() {
    int op;
    do {
        cout << "--- Solicitudes y Contratos ---" << endl;
        cout << "1) Crear solicitud" << endl;
        cout << "2) Ver solicitudes" << endl;
        cout << "3) Aprobar/Rechazar solicitud" << endl;
        cout << "4) Recepcion de vehiculo y finalizacion de contrato" << endl;
        cout << "0) Atras" << endl;
        op = leerIntRango("Opcion: ", 0, 4);
        if (op == 1) crearSolicitud();
        else if (op == 2) verSolicitudes();
        else if (op == 3) aprobarRechazarSolicitud();
        else if (op == 4) recibirYFinalizarContrato();
    } while (op != 0);
}

void Menu::crearSolicitud() {
    cout << endl << "Crear Solicitud de Alquiler" << endl;

    string idSol = leerLinea("Codigo de solicitud: ");
    string fecha = leerLinea("Fecha de solicitud (YYYY-MM-DD): ");

    string idCli = leerLinea("ID del cliente: ");
    Cliente* cli = lsClientes->buscar(idCli);
    if (cli == NULL) {
        cout << "No existe un cliente con ese ID." << endl;
        esperarEnter();
        return;
    }

    string placa = leerLinea("Placa del vehiculo: ");
    Vehiculo* v = lsVehiculos->buscar(placa);
    if (v == NULL) {
        cout << "No existe un vehiculo con esa placa." << endl;
        esperarEnter();
        return;
    }

    SolicitudAlquiler* s = new SolicitudAlquiler(idSol, fecha, "Pendiente", cli, v);
    lsSolicitudes->insertarFinal(new NodoSolicitud(s));

    cout << "Solicitud creada exitosamente." << endl;
    esperarEnter();
}



void Menu::verSolicitudes() {
    cout << lsSolicitudes->toString();
    esperarEnter();
}

void Menu::aprobarRechazarSolicitud() {
    cout << endl << "Aprobar o Rechazar Solicitud" << endl;

    string idSol = leerLinea("Codigo de solicitud: ");
    SolicitudAlquiler* sol = lsSolicitudes->buscar(idSol);
    if (sol == NULL) {
        cout << "No existe una solicitud con ese codigo." << endl;
        esperarEnter();
        return;
    }

    cout << "Estado actual: " << sol->getEstado() << endl;
    if (sol->getEstado() != "Pendiente") {
        cout << "Solo se pueden procesar solicitudes en estado 'Pendiente'." << endl;
        esperarEnter();
        return;
    }

    cout << "1) Aprobar" << endl;
    cout << "2) Rechazar" << endl;
    int op = leerIntRango("Opcion: ", 1, 2);

    if (op == 2) {
        sol->setEstado("Rechazada");
        cout << "Solicitud rechazada." << endl;
        esperarEnter();
        return;
    }

    //aprobar
    sol->setEstado("Aprobada");

    string idCon = leerLinea("Codigo de contrato: ");
    string fIni = leerLinea("Fecha de inicio (YYYY-MM-DD): ");
    string fFin = leerLinea("Fecha de fin (YYYY-MM-DD): ");
    string idCol = leerLinea("ID colaborador que aprueba: ");
    Colaborador* col = lsColabs->buscar(idCol);
    if (col == NULL) {
        cout << "No existe un colaborador con ese ID." << endl;
        esperarEnter();
        return;
    }

    cout << "Monto total: ";
    string tmp; getline(cin, tmp);
    double monto = 0.0;
    {
        stringstream ss(tmp);
        ss >> monto;
        if (ss.fail()) monto = 0.0;
    }

    ContratoAlquiler* c = new ContratoAlquiler(
        idCon, fIni, fFin, monto,
        sol->getCliente(), sol->getVehiculo(), col
    );
    c->setSolicitud(sol);

    lsContratos->insertarFinal(new NodoContrato(c));

    Vehiculo* v = sol->getVehiculo();
    if (v != NULL) {
        v->setEstado("Alquilado");
    }

    cout << "Solicitud aprobada y contrato creado." << endl;
    esperarEnter();
}


void Menu::recibirYFinalizarContrato() {
    cout << endl << "Recepcion de Vehiculo y Cierre de Contrato" << endl;

    string idCon = leerLinea("Codigo de contrato: ");
    ContratoAlquiler* c = lsContratos->buscar(idCon);
    if (c == NULL) {
        cout << "No existe un contrato con ese codigo." << endl;
        esperarEnter();
        return;
    }

    string fechaReal = leerLinea("Fecha de devolucion real (YYYY-MM-DD): ");
    c->setFechaFin(fechaReal);

    Vehiculo* v = c->getVehiculo();
    if (v != NULL) {
        v->setEstado("Disponible");

        for (NodoPlantel* np = lsPlanteles->getPpio(); np != NULL; np = np->getSiguiente()) {
            Plantel* p = np->getDato();
            EspacioEstacionamiento** m = p->getMatriz();
            if (!m) continue;

            for (int i = 0; i < p->getFilas(); i++) {
                for (int j = 0; j < p->getColumnas(); j++) {
                    EspacioEstacionamiento* e = &m[i][j];
                    if (e->getVehiculo() != NULL && e->getVehiculo()->getPlaca() == v->getPlaca()) {
                        e->setVehiculo(NULL);
                        e->setEstado("Disponible");
                    }
                }
            }
        }
    }

    cout << "Vehiculo recibido. Contrato actualizado con fecha de devolucion." << endl;
    esperarEnter();
}


void Menu::menuReportesCliente() {
    menuReportesClienteImpl();
}
void Menu::menuReportesPlantelVehiculos() {
    menuReportesPlantelVehImpl();
}
void Menu::menuReportesAlquileres() {
    menuReportesAlquileresImpl();

}

void Menu::menuReportesClienteImpl() {
    int op;
    do {
        cout << "--- Reportes de Cliente ---" << endl;
        cout << "1) Historial del cliente" << endl;
        cout << "2) Clientes por cantidad de contratos" << endl;
        cout << "0) Atras" << endl;
        op = leerIntRango("Opcion: ", 0, 2);
        if (op == 1) reporteHistorialCliente();
        else if (op == 2) reporteClientesPorContratos();
    } while (op != 0);
}

void Menu::menuReportesPlantelVehImpl() {
    int op;
    do {
        cout << "--- Reportes de Planteles y Vehiculos ---" << endl;
        cout << "1) Estados de un vehiculo (bitacora)" << endl;
        cout << "2) Contratos por vehiculo" << endl;
        cout << "3) % de ocupacion de planteles" << endl;
        cout << "0) Atras" << endl;
        op = leerIntRango("Opcion: ", 0, 3);
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
        cout << "0) Atras" << endl;
        op = leerIntRango("Opcion: ", 0, 2);
        if (op == 1) verContratosPorSucursal();
        else if (op == 2) reporteAlquileresPorColaborador();
    } while (op != 0);
}

void Menu::reporteHistorialCliente() {
    cout << endl << "Historial del cliente" << endl;

    string idCli = leerLinea("ID del cliente: ");

    cout << endl << "Solicitudes" << endl;
    {
        bool hay = false;
        NodoSolicitud* ns = lsSolicitudes->getPpio();
        while (ns != NULL) {
            SolicitudAlquiler* s = ns->getDato();
            if (s != NULL && s->getCliente() != NULL && s->getCliente()->getId() == idCli) {
                cout << s->toString() << endl;
                hay = true;
            }
            ns = ns->getSiguiente();
        }
        if (!hay) cout << "Sin solicitudes" << endl;
    }

    cout << endl << "Contratos" << endl;
    {
        bool hay = false;
        NodoContrato* nc = lsContratos->getPpio();
        while (nc != NULL) {
            ContratoAlquiler* c = nc->getDato();
            if (c != NULL && c->getCliente() != NULL && c->getCliente()->getId() == idCli) {
                cout << c->toString() << endl;
                hay = true;
            }
            nc = nc->getSiguiente();
        }
        if (!hay) cout << "Sin contratos" << endl;
    }

    esperarEnter();
}

void Menu::reporteClientesPorContratos() {
    cout << endl << "--- Clientes por cantidad de contratos ---" << endl;
    string impresos = "";

    int totalClientes = 0;
    for (NodoCliente* nc = lsClientes->getPpio(); nc != NULL; nc = nc->getSiguiente()) totalClientes++;

    for (int k = 0; k < totalClientes; k++) {
        // buscar el cliente con mayor #contratos que NO este
        Cliente* mejor = NULL;
        int maxC = -1;

        for (NodoCliente* nc = lsClientes->getPpio(); nc != NULL; nc = nc->getSiguiente()) {
            Cliente* cli = nc->getDato();
            if (cli == NULL) continue;

            string id = cli->getId();
            string marca = string("|") + id + string("|");
            if (impresos.find(marca) != string::npos) continue;

            // contar contratos
            int cont = 0;
            for (NodoContrato* nd = lsContratos->getPpio(); nd != NULL; nd = nd->getSiguiente()) {
                ContratoAlquiler* c = nd->getDato();
                if (c != NULL && c->getCliente() != NULL && c->getCliente()->getId() == id) cont++;
            }

            if (cont > maxC) {
                maxC = cont;
                mejor = cli;
            }
        }

        if (mejor == NULL) break;

        cout << "Cliente: " << mejor->getId() << " - " << mejor->getNom()
            << " | Contratos: " << maxC << endl;

        for (NodoContrato* nd = lsContratos->getPpio(); nd != NULL; nd = nd->getSiguiente()) {
            ContratoAlquiler* c = nd->getDato();
            if (c != NULL && c->getCliente() != NULL && c->getCliente()->getId() == mejor->getId()) {
                cout << "   - Contrato: " << c->getIdContrato() << endl;
            }
        }

        impresos += string("|") + mejor->getId() + string("|");
    }

    esperarEnter();
}

void Menu::reporteEstadosVehiculo() {
    cout << endl << "Bitacora de estados de un vehiculo" << endl;

    string placa = leerLinea("Placa: ");
    ifstream in("bitacora_vehiculos.txt");
    if (!in) {
        cout << "No existe bitacora_vehiculos.txt" << endl;
        esperarEnter();
        return;
    }

    bool hay = false;
    string linea;
    while (getline(in, linea)) {
        size_t p = linea.find('|');
        if (p != string::npos) {
            string pl = linea.substr(0, p);
            if (pl == placa) {
                cout << linea << endl;
                hay = true;
            }
        }
    }
    if (!hay) cout << "(Sin registros para esa placa)" << endl;

    in.close();
    esperarEnter();
}

void Menu::reporteContratosPorVehiculo() {
    cout << endl << "Contratos por vehiculo" << endl;

    string placa = leerLinea("Placa: ");
    bool hay = false;

    for (NodoContrato* nd = lsContratos->getPpio(); nd != NULL; nd = nd->getSiguiente()) {
        ContratoAlquiler* c = nd->getDato();
        if (c != NULL && c->getVehiculo() != NULL && c->getVehiculo()->getPlaca() == placa) {
            cout << c->toString() << endl;
            hay = true;
        }
    }

    if (!hay) cout << "(Sin contratos para esa placa)" << endl;
    esperarEnter();
}

void Menu::reporteOcupacionPlanteles() {
    cout << endl << "Porcentaje de ocupacion por plantel" << endl;

    for (NodoPlantel* np = lsPlanteles->getPpio(); np != NULL; np = np->getSiguiente()) {
        Plantel* p = np->getDato();
        if (p == NULL) continue;

        EspacioEstacionamiento** m = p->getMatriz();
        int F = p->getFilas(), C = p->getColumnas();
        int total = F * C;
        int ocup = 0;

        if (m != NULL) {
            for (int i = 0; i < F; i++) {
                for (int j = 0; j < C; j++) {
                    if (m[i][j].getVehiculo() != NULL || m[i][j].getEstado() == string("Ocupado")) {
                        ocup++;
                    }
                }
            }
        }

        // porcentaje entero
        int porc = (total > 0) ? (ocup * 100 / total) : 0;
        cout << "Plantel " << p->getLetra() << " -> " << porc << "% (" << ocup << "/" << total << ")" << endl;
    }

    esperarEnter();
}
// compara fecha YYYY-MM-DD descendente
static bool fechaMayorIgual(const string& a, const string& b) {
    return a >= b;
}

void Menu::verContratosPorSucursal() {
    cout << endl << "Contratos por sucursal (reciente -> antiguo)" << endl;

    string codSuc = leerLinea("Codigo de sucursal: ");
    string impresos = "";

    // Contar cuantos candidatos hay de esa sucursal
    int total = 0;
    for (NodoContrato* nd = lsContratos->getPpio(); nd != NULL; nd = nd->getSiguiente()) {
        ContratoAlquiler* c = nd->getDato();
        if (c != NULL && c->getColaborador() != NULL && c->getColaborador()->getSucursalAsignada() == codSuc) {
            total++;
        }
    }

    for (int k = 0; k < total; k++) {
        ContratoAlquiler* mejor = NULL;
        string idMejor = "";
        string fMejor = "";

        for (NodoContrato* nd = lsContratos->getPpio(); nd != NULL; nd = nd->getSiguiente()) {
            ContratoAlquiler* c = nd->getDato();
            if (c == NULL || c->getColaborador() == NULL) continue;
            if (c->getColaborador()->getSucursalAsignada() != codSuc) continue;

            string idc = c->getIdContrato();
            string marca = string("|") + idc + string("|");
            if (impresos.find(marca) != string::npos) continue;

            string fIni = c->getFechaInicio();
            if (mejor == NULL || fechaMayorIgual(fIni, fMejor)) {
                mejor = c;
                idMejor = idc;
                fMejor = fIni;
            }
        }

        if (mejor == NULL) break;

        cout << mejor->toString() << endl;
        impresos += string("|") + idMejor + string("|");
    }

    if (impresos.empty()) cout << "(Sin contratos para esa sucursal)" << endl;
    esperarEnter();
}

void Menu::reporteAlquileresPorColaborador() {
    cout << endl << "Reporte de alquileres por colaborador" << endl;

    string idCol = leerLinea("ID del colaborador: ");
    bool hay = false;

    for (NodoContrato* nd = lsContratos->getPpio(); nd != NULL; nd = nd->getSiguiente()) {
        ContratoAlquiler* c = nd->getDato();
        if (c != NULL && c->getColaborador() != NULL && c->getColaborador()->getId() == idCol) {
            cout << c->toString() << endl;
            hay = true;
        }
    }

    if (!hay) cout << "(Sin contratos asociados a ese colaborador)" << endl;
    esperarEnter();
}


Sucursal* Menu::seleccionarSucursalPorCodigo(string mensaje) {
    string cod = leerLinea(mensaje);
    return lsSucursales->buscar(cod);
}

Plantel* Menu::seleccionarPlantelPorLetra() {
    string sl = leerLinea("Letra de plantel: ");
    char letra = sl.empty() ? 'A' : sl[0];

    for (NodoPlantel* n = lsPlanteles->getPpio(); n; n = n->getSiguiente()) {
        if (n->getDato()->getLetra() == letra) return n->getDato();
    }
    cout << "No se encontro plantel." << endl;
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

EspacioEstacionamiento* Menu::buscarEspacioPorCodigo(Plantel* p,string codigoEsp) {
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