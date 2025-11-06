#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
#include "ListaSucursal.h"
#include "ListaCliente.h"
#include "ListaColaborador.h"
#include "ListaPlantel.h"
#include "ListaVehiculo.h"
#include "ListaSolicitud.h"
#include "ListaContrato.h"
#include "ArchivoSucursal.h"
#include "ArchivoCliente.h"
#include "ArchivoColaborador.h"
#include "ArchivoPlantel.h"
#include "ArchivoVehiculo.h"
#include "ArchivoSolicitud.h"
#include "ArchivoContrato.h"

class Menu {
private:
    ListaSucursal* lsSucursales;
    ListaCliente* lsClientes;
    ListaColaborador* lsColabs;
    ListaPlantel* lsPlanteles;
    ListaVehiculo* lsVehiculos;
    ListaSolicitud* lsSolicitudes;
    ListaContrato* lsContratos;

    ArchivoSucursal arcSuc;
    ArchivoCliente arcCli;
    ArchivoColaborador arcCol;
    ArchivoPlantel arcPla;
    ArchivoVehiculo arcVeh;
    ArchivoSolicitud arcSol;
    ArchivoContrato arcCon;

public:
    Menu(ListaSucursal*, ListaCliente*, ListaColaborador*, ListaPlantel*, ListaVehiculo*, ListaSolicitud*, ListaContrato*);
    Menu();
    ~Menu();
    void run();

private:
    void menuPrincipal();
    void datosGenerales();
    void menuPlantelesVehiculos();
    void menuSolicitudesContratos();
    void menuReportesCliente();
    void menuReportesPlantelVehiculos();
    void menuReportesAlquileres();

    static int leerIntRango(string, int, int);
    static int leerInt(string);
    static string leerLinea(string);
    static void esperarEnter();

    void crearSucursal();
    void eliminarSucursal();
    void verSucursales();

    void crearCliente();
    void eliminarCliente();
    void verClientes();

    void crearColaborador();
    void eliminarColaborador();
    void verColaboradores();

    void crearPlantel(); 
    void verDistribucionPlantel();
    void ingresarVehiculo();
    void eliminarVehiculo();
    void verVehiculos();
    void reubicarVehiculo(); 
    void cambiarEstadoVehiculo(); 
    void trasladarVehiculos();

    void crearSolicitud();
    void verSolicitudes();
    void aprobarRechazarSolicitud();
    void recibirYFinalizarContrato();

    void menuReportesClienteImpl();
    void menuReportesPlantelVehImpl();
    void menuReportesAlquileresImpl();

    void reporteHistorialCliente();
    void reporteClientesPorContratos();
    void reporteEstadosVehiculo();
    void reporteContratosPorVehiculo();
    void reporteOcupacionPlanteles();
    void verContratosPorSucursal();
    void reporteAlquileresPorColaborador();

    Sucursal* seleccionarSucursalPorCodigo(string);
    Plantel* seleccionarPlantelPorLetra();
    EspacioEstacionamiento* recomendarEspacio(Plantel*);
    EspacioEstacionamiento* buscarEspacioPorCodigo(Plantel*,string);
    void dibujarMatriz(Plantel*);
};
