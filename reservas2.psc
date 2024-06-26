Algoritmo reservas
	Definir  numPersonas, numDias, tipoHabitacion, reservacionesRealizadas Como Entero
    Definir  nombreCliente, opcion Como Cadena
    Definir salir Como Logico
    Definir costoTotal, descuentoAdultoMayor, descuentoNino, gananciasDelDia, montoPagado, cambio Como Real
	descuentoAdultoMayor <- 0.3
    descuentoNino <- 0.2
    gananciasDelDia <- 0.0
    reservacionesRealizadas <- 0    
    numHabitaciones <-4
	
	Dimension habitacionesNombre[4]
    Dimension habitacionesCapacidadMaxima[4]
    Dimension habitacionesCostoPorNoche[4]
    habitacionesNombre[1] <- "Habitaci�n Normal"
    habitacionesCapacidadMaxima[1] <- 3
    habitacionesCostoPorNoche[1] <- 3000
    habitacionesNombre[2] <- "Suite"
    habitacionesCapacidadMaxima[2] <- 6
    habitacionesCostoPorNoche[2] <- 8000
    habitacionesNombre[3] <- "Habitaci�n Imperial"
    habitacionesCapacidadMaxima[3] <- 10
    habitacionesCostoPorNoche[3] <- 12000
    habitacionesNombre[4] <- "Villa"
    habitacionesCapacidadMaxima[4] <- 15
    habitacionesCostoPorNoche[4] <- 20000
	
	
	Escribir "Bienvenido al Hotel Paralish"
	Escribir "�Desea hacer una reserva? (s/n):"
	Leer opcion
	Si opcion = "s" entonces
		Escribir "Ingrese su nombre:"
		Leer nombreCliente
		Escribir "Ingrese el n�mero de personas que estar�n en la habitaci�n (incluyendo usted):"
		Leer numPersonas
		Escribir "Ingrese el n�mero de d�as de estancia:"
		Leer numDias
		Escribir "Seleccione el tipo de habitaci�n (1 - 4):"
		Leer tipoHabitacion
		
		Si tipoHabitacion < 1 O tipoHabitacion > 4 Entonces
			Escribir "Tipo de habitaci�n inv�lido."
			// Volver al men� principal
		FinSi
		
		Si numPersonas > habitacionesCapacidadMaxima[tipoHabitacion] Entonces
			Escribir "El n�mero de personas excede la capacidad m�xima de la habitaci�n."
			// Volver al men� principal
		FinSi
		
		costoTotal <- habitacionesCostoPorNoche[tipoHabitacion] * numDias
		Si numPersonas < 10 Entonces
			costoTotal <- costoTotal * (1 - descuentoNino)
		Finsi
		Si numDias > 60 Entonces
			costoTotal <- costoTotal * (1 - descuentoAdultoMayor)
		FinSi
		
		Escribir "El costo total de la reserva es: $", costoTotal
		Escribir "Ingrese el monto con el que va a pagar:"
		Leer montoPagado
		Mientras montoPagado < costoTotal Hacer
			Escribir "Monto insuficiente. Ingrese al menos $", costoTotal, ":"
			Leer montoPagado
		FinMientras
		
		cambio <- montoPagado - costoTotal
		Si cambio > 0 Entonces
			Escribir "Su cambio es: $", cambio
		FinSi 		
		
		gananciasDelDia <- gananciasDelDia + costoTotal
		reservacionesRealizadas <- reservacionesRealizadas + 1
		Escribir "�Reserva realizada exitosamente!"
		Escribir "Reservaciones del d�a: ", reservacionesRealizadas
		Escribir "Ganancias totales del d�a: $", gananciasDelDia
		Escribir "Gracias por visitarnos. �Hasta luego!"
	FinSi
	
FinAlgoritmo
