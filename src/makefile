CC = g++
DEBUG = -g
CFLAGS = -Wall -pedantic -pthread -std=c++11 -c $(DEBUG)
LFLAGS = -Wall $(DEBUG) -pthread
FFLAGS = -o $@
LIBS = -lsfml-system -lsfml-window -lsfml-graphics -lsfml-network -lsfml-audio
EXEC = game

../obj/Logger.o: ./Utilities/Logger.cpp ./Utilities/Logger.hpp
	$(CC) $(CFLAGS) ./Utilities/Logger.cpp $(FFLAGS)

../obj/main.o: ./main.cpp
	$(CC) $(CFLAGS) ./main.cpp $(FFLAGS)

../obj/TaskManagerInterface.o: ./Engine/Managers/TaskManagerInterface.cpp ./Engine/Managers/TaskManagerInterface.hpp
	$(CC) $(CFLAGS) ./Engine/Managers/TaskManagerInterface.cpp $(FFLAGS)

../obj/EnvironmentManager.o: ./Engine/Managers/EnvironmentManager.cpp ./Engine/Managers/EnvironmentManager.hpp
	$(CC) $(CFLAGS) ./Engine/Managers/EnvironmentManager.cpp $(FFLAGS)

../obj/StateManager.o: ./Engine/Managers/StateManager.cpp ./Engine/Managers/StateManager.hpp
	$(CC) $(CFLAGS) ./Engine/Managers/StateManager.cpp $(FFLAGS)

../obj/TaskManager.o: ./Engine/Managers/TaskManager.cpp ./Engine/Managers/TaskManager.hpp
	$(CC) $(CFLAGS) ./Engine/Managers/TaskManager.cpp $(FFLAGS)

../obj/Manager.o: ./Engine/Managers/Manager.cpp ./Engine/Managers/Manager.hpp
	$(CC) $(CFLAGS) ./Engine/Managers/Manager.cpp $(FFLAGS)

../obj/EnvironmentManagerInterface.o: ./Engine/Managers/EnvironmentManagerInterface.cpp ./Engine/Managers/EnvironmentManagerInterface.hpp
	$(CC) $(CFLAGS) ./Engine/Managers/EnvironmentManagerInterface.cpp $(FFLAGS)

../obj/UObject.o: ./Engine/Framework/UEntities/UObject.cpp ./Engine/Framework/UEntities/UObject.hpp
	$(CC) $(CFLAGS) ./Engine/Framework/UEntities/UObject.cpp $(FFLAGS)

../obj/UScene.o: ./Engine/Framework/UEntities/UScene.cpp ./Engine/Framework/UEntities/UScene.hpp
	$(CC) $(CFLAGS) ./Engine/Framework/UEntities/UScene.cpp $(FFLAGS)

../obj/Framework.o: ./Engine/Framework/Framework.cpp ./Engine/Framework/Framework.hpp
	$(CC) $(CFLAGS) ./Engine/Framework/Framework.cpp $(FFLAGS)

../obj/Scheduler.o: ./Engine/Framework/Scheduler/Scheduler.cpp ./Engine/Framework/Scheduler/Scheduler.hpp
	$(CC) $(CFLAGS) ./Engine/Framework/Scheduler/Scheduler.cpp $(FFLAGS)

../obj/Engine.o: ./Engine/Engine.cpp ./Engine/Engine.hpp
	$(CC) $(CFLAGS) ./Engine/Engine.cpp $(FFLAGS)

../obj/SceneExtension.o: ./Systems/EntityExtensions/SceneExtension.cpp ./Systems/EntityExtensions/SceneExtension.hpp
	$(CC) $(CFLAGS) ./Systems/EntityExtensions/SceneExtension.cpp $(FFLAGS)

../obj/ObjectExtension.o: ./Systems/EntityExtensions/ObjectExtension.cpp ./Systems/EntityExtensions/ObjectExtension.hpp
	$(CC) $(CFLAGS) ./Systems/EntityExtensions/ObjectExtension.cpp $(FFLAGS)

../obj/GraphicObjectExtension.o: ./Systems/EntityExtensions/GraphicObjectExtension.cpp ./Systems/EntityExtensions/GraphicObjectExtension.hpp
	$(CC) $(CFLAGS) ./Systems/EntityExtensions/GraphicObjectExtension.cpp $(FFLAGS)

../obj/LogicObject.o: ./Systems/Logic/LogicObject.cpp ./Systems/Logic/LogicObject.hpp
	$(CC) $(CFLAGS) ./Systems/Logic/LogicObject.cpp $(FFLAGS)

../obj/LogicSystem.o: ./Systems/Logic/LogicSystem.cpp ./Systems/Logic/LogicSystem.hpp
	$(CC) $(CFLAGS) ./Systems/Logic/LogicSystem.cpp $(FFLAGS)

../obj/LogicScene.o: ./Systems/Logic/LogicScene.cpp ./Systems/Logic/LogicScene.hpp
	$(CC) $(CFLAGS) ./Systems/Logic/LogicScene.cpp $(FFLAGS)

../obj/SystemInterface.o: ./Systems/SystemInterface.cpp ./Systems/SystemInterface.hpp
	$(CC) $(CFLAGS) ./Systems/SystemInterface.cpp $(FFLAGS)

../obj/System.o: ./Systems/System.cpp ./Systems/System.hpp
	$(CC) $(CFLAGS) ./Systems/System.cpp $(FFLAGS)

clean:
	rm ../obj/*.o

../obj/:
	mkdir ../obj/

OBJDIR:|../obj/

$(EXEC): ../obj/Logger.o ../obj/main.o ../obj/TaskManagerInterface.o ../obj/EnvironmentManager.o ../obj/StateManager.o ../obj/TaskManager.o ../obj/Manager.o ../obj/EnvironmentManagerInterface.o ../obj/UObject.o ../obj/UScene.o ../obj/Framework.o ../obj/Scheduler.o ../obj/Engine.o ../obj/SceneExtension.o ../obj/ObjectExtension.o ../obj/GraphicObjectExtension.o ../obj/LogicObject.o ../obj/LogicSystem.o ../obj/LogicScene.o ../obj/SystemInterface.o ../obj/System.o
	$(CC) $(LFLAGS) -o $(EXEC) ../obj/*.o $(LIBS)

.DEFAULT_GOAL:=$(EXEC)

.PHONY:clean OBJDIR
