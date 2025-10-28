#include "EspacioEstacionammiento.h"

EspacioEstacionamiento::EspacioEstacionamiento()
{
	this->codigo = "";
	this->estado = "Disponible";
	this->vehiculo = nullptr;
}

EspacioEstacionamiento::EspacioEstacionamiento(string codigo)
{
	this->codigo = codigo;
	this->estado = "Disponible";
	this->vehiculo = nullptr;
}

EspacioEstacionamiento::~EspacioEstacionamiento()
{
	vehiculo = nullptr;//Aqui esto no elimina, solo desconecta 
}

string EspacioEstacionamiento::getCodigo() { return codigo; }
string EspacioEstacionamiento::getEstado() { return estado; }
Vehiculo* EspacioEstacionamiento::getVehiculo() { return vehiculo; }

void EspacioEstacionamiento::setCodigo(string codigo) { this->codigo = codigo; }
void EspacioEstacionamiento::setEstado(string estado) { this->estado = estado; }
void EspacioEstacionamiento::setVehiculo(Vehiculo* vehiculo) { this->vehiculo = vehiculo; }

void EspacioEstacionamiento::mostrar()
{
	stringstream ss;
	ss << "Codigo: " << codigo << " | Estado: " << estado;
	if (vehiculo != nullptr)
		ss << " | Vehiculo asignado.";
	else
		ss << " | Sin vehiculo.";

	cout << ss.str() << endl;
}
