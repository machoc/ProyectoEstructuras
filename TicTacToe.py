import os
import platform 

platform.system() == "Linux":
	os.system ("git clone https://github.com/machoc/ProyectoEstructuras")
	os.system ("g++ -std=c++14 ProyectoEstructuras/archivoshcpp/*.cpp ProyectoEstructuras/archivoshcpp/*.h -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system")
	os.system ("cp -r ProyectoEstructuras/archivoshcpp/imagenesJuego .")
	os.system ("./sfml-app")