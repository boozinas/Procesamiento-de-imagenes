#pragma once
ref class OpPuntual
{
public:
	OpPuntuales();
};

void OpPuntual::ImprimirInfo()
{
	cout << "Nombre: " << m_nombre << '\n';
	cout << "Departamento: " << m_departamento << '\n';
	cout << "Puesto: " << m_posicion << '\n';
	cout << "Salario: " << m_salario << '\n';
}