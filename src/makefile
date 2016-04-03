CC = g++
DEBUG = -g
CFLAGS = -Wall -pedantic -pthread -std=c++11 -c $(DEBUG)
LFLAGS = -Wall $(DEBUG) -pthread
FFLAGS = -o $@
LIBS = -lsfml-system -lsfml-window -lsfml-graphics -lsfml-network -lsfml-audio -lX11
EXEC = game

../obj/Logger.o: Utilities/Logger.cpp Utilities/./Logger.hpp
	$(CC) $(CFLAGS) ./Utilities/Logger.cpp $(FFLAGS)


../obj/main.o: main.cpp Systems/Graphics/GraphicSystemInterface.hpp \
 Systems/Graphics/./GraphicSystem.hpp Systems/Graphics/./../System.hpp \
 Systems/Graphics/./../helixStructures.hpp \
 Systems/Graphics/./../../Engine/Managers/IntBundle.hpp \
 Systems/Graphics/./../../Engine/Managers/./MgrBundle.hpp \
 Systems/Graphics/./../../Engine/Managers/././TaskManagerInterface.hpp \
 Systems/Graphics/./../../Engine/Managers/./././ManagerInterface.hpp \
 Systems/Graphics/./../../Engine/Managers/./././Manager.hpp \
 Systems/Graphics/./../../Engine/Managers/./././TaskManager.hpp \
 Systems/Graphics/./../../Engine/Managers/./././../../Utilities/Logger.hpp \
 Systems/Graphics/./../../Engine/Managers/././StateManagerInterface.hpp \
 Systems/Graphics/./../../Engine/Managers/./././StateManager.hpp \
 Systems/Graphics/./../../Engine/Managers/././ServiceManagerInterface.hpp \
 Systems/Graphics/./../../Engine/Managers/./././ServiceManager.hpp \
 Systems/Graphics/./../../Engine/Managers/././EnvironmentManagerInterface.hpp \
 Systems/Graphics/./../../Engine/Managers/./././EnvironmentManager.hpp \
 Systems/Graphics/./../../Engine/Managers/././PlatformManagerInterface.hpp \
 Systems/Graphics/./../../Engine/Managers/./././PlatformManager.hpp \
 Systems/Graphics/././GraphicScene.hpp \
 Systems/Graphics/./././GraphicObject.hpp \
 Systems/Graphics/./././../EntityExtensions/ObjectExtension.hpp \
 Systems/Graphics/././../EntityExtensions/SceneExtension.hpp \
 Systems/Graphics/../SystemInterface.hpp \
 Systems/Logic/LogicSystemInterface.hpp Systems/Logic/./LogicSystem.hpp \
 Systems/Logic/././LogicScene.hpp Systems/Logic/./././LogicObject.hpp \
 Engine/Engine.hpp Engine/./Framework/Framework.hpp \
 Engine/./Framework/./Scheduler/Scheduler.hpp \
 Engine/./Framework/./UEntities/UScene.hpp
	$(CC) $(CFLAGS) ./main.cpp $(FFLAGS)


../obj/TaskManagerInterface.o: Engine/Managers/TaskManagerInterface.cpp \
 Engine/Managers/./TaskManagerInterface.hpp \
 Engine/Managers/././ManagerInterface.hpp Engine/Managers/././Manager.hpp \
 Engine/Managers/././TaskManager.hpp \
 Engine/Managers/././../../Utilities/Logger.hpp
	$(CC) $(CFLAGS) ./Engine/Managers/TaskManagerInterface.cpp $(FFLAGS)


../obj/EnvironmentManager.o: Engine/Managers/EnvironmentManager.cpp \
 Engine/Managers/./EnvironmentManager.hpp Engine/Managers/./Manager.hpp
	$(CC) $(CFLAGS) ./Engine/Managers/EnvironmentManager.cpp $(FFLAGS)


../obj/IntBundle.o: Engine/Managers/IntBundle.cpp \
 Engine/Managers/./IntBundle.hpp Engine/Managers/././MgrBundle.hpp \
 Engine/Managers/./././TaskManagerInterface.hpp \
 Engine/Managers/././././ManagerInterface.hpp \
 Engine/Managers/././././Manager.hpp \
 Engine/Managers/././././TaskManager.hpp \
 Engine/Managers/././././../../Utilities/Logger.hpp \
 Engine/Managers/./././StateManagerInterface.hpp \
 Engine/Managers/././././StateManager.hpp \
 Engine/Managers/./././ServiceManagerInterface.hpp \
 Engine/Managers/././././ServiceManager.hpp \
 Engine/Managers/./././EnvironmentManagerInterface.hpp \
 Engine/Managers/././././EnvironmentManager.hpp \
 Engine/Managers/./././PlatformManagerInterface.hpp \
 Engine/Managers/././././PlatformManager.hpp
	$(CC) $(CFLAGS) ./Engine/Managers/IntBundle.cpp $(FFLAGS)


../obj/StateManager.o: Engine/Managers/StateManager.cpp \
 Engine/Managers/./StateManager.hpp Engine/Managers/././Manager.hpp
	$(CC) $(CFLAGS) ./Engine/Managers/StateManager.cpp $(FFLAGS)


../obj/ServiceManager.o: Engine/Managers/ServiceManager.cpp \
 Engine/Managers/./ServiceManager.hpp Engine/Managers/././Manager.hpp
	$(CC) $(CFLAGS) ./Engine/Managers/ServiceManager.cpp $(FFLAGS)


../obj/PlatformManagerInterface.o: Engine/Managers/PlatformManagerInterface.cpp \
 Engine/Managers/./PlatformManagerInterface.hpp \
 Engine/Managers/././PlatformManager.hpp \
 Engine/Managers/./././Manager.hpp \
 Engine/Managers/././ManagerInterface.hpp
	$(CC) $(CFLAGS) ./Engine/Managers/PlatformManagerInterface.cpp $(FFLAGS)


../obj/TaskManager.o: Engine/Managers/TaskManager.cpp \
 Engine/Managers/./TaskManager.hpp Engine/Managers/././Manager.hpp \
 Engine/Managers/./../../Utilities/Logger.hpp
	$(CC) $(CFLAGS) ./Engine/Managers/TaskManager.cpp $(FFLAGS)


../obj/ServiceManagerInterface.o: Engine/Managers/ServiceManagerInterface.cpp \
 Engine/Managers/ServiceManagerInterface.hpp \
 Engine/Managers/./ServiceManager.hpp Engine/Managers/././Manager.hpp \
 Engine/Managers/./ManagerInterface.hpp
	$(CC) $(CFLAGS) ./Engine/Managers/ServiceManagerInterface.cpp $(FFLAGS)


../obj/MgrBundle.o: Engine/Managers/MgrBundle.cpp \
 Engine/Managers/./MgrBundle.hpp \
 Engine/Managers/././TaskManagerInterface.hpp \
 Engine/Managers/./././ManagerInterface.hpp \
 Engine/Managers/./././Manager.hpp Engine/Managers/./././TaskManager.hpp \
 Engine/Managers/./././../../Utilities/Logger.hpp \
 Engine/Managers/././StateManagerInterface.hpp \
 Engine/Managers/./././StateManager.hpp \
 Engine/Managers/././ServiceManagerInterface.hpp \
 Engine/Managers/./././ServiceManager.hpp \
 Engine/Managers/././EnvironmentManagerInterface.hpp \
 Engine/Managers/./././EnvironmentManager.hpp \
 Engine/Managers/././PlatformManagerInterface.hpp \
 Engine/Managers/./././PlatformManager.hpp
	$(CC) $(CFLAGS) ./Engine/Managers/MgrBundle.cpp $(FFLAGS)


../obj/Manager.o: Engine/Managers/Manager.cpp Engine/Managers/Manager.hpp
	$(CC) $(CFLAGS) ./Engine/Managers/Manager.cpp $(FFLAGS)


../obj/EnvironmentManagerInterface.o: \
 Engine/Managers/EnvironmentManagerInterface.cpp \
 Engine/Managers/./EnvironmentManagerInterface.hpp \
 Engine/Managers/././ManagerInterface.hpp Engine/Managers/././Manager.hpp \
 Engine/Managers/././EnvironmentManager.hpp
	$(CC) $(CFLAGS) ./Engine/Managers/EnvironmentManagerInterface.cpp $(FFLAGS)


../obj/StateManagerInterface.o: Engine/Managers/StateManagerInterface.cpp \
 Engine/Managers/./StateManagerInterface.hpp \
 Engine/Managers/././StateManager.hpp Engine/Managers/./././Manager.hpp \
 Engine/Managers/././ManagerInterface.hpp
	$(CC) $(CFLAGS) ./Engine/Managers/StateManagerInterface.cpp $(FFLAGS)


../obj/PlatformManager.o: Engine/Managers/PlatformManager.cpp \
 Engine/Managers/./PlatformManager.hpp Engine/Managers/././Manager.hpp
	$(CC) $(CFLAGS) ./Engine/Managers/PlatformManager.cpp $(FFLAGS)


../obj/UObject.o: Engine/Framework/UEntities/UObject.cpp \
 Engine/Framework/UEntities/UObject.hpp
	$(CC) $(CFLAGS) ./Engine/Framework/UEntities/UObject.cpp $(FFLAGS)


../obj/UScene.o: Engine/Framework/UEntities/UScene.cpp \
 Engine/Framework/UEntities/UScene.hpp
	$(CC) $(CFLAGS) ./Engine/Framework/UEntities/UScene.cpp $(FFLAGS)


../obj/Framework.o: Engine/Framework/Framework.cpp \
 Engine/Framework/./Framework.hpp \
 Engine/Framework/././Scheduler/Scheduler.hpp \
 Engine/Framework/././Scheduler/../../Managers/TaskManagerInterface.hpp \
 Engine/Framework/././Scheduler/../../Managers/./ManagerInterface.hpp \
 Engine/Framework/././Scheduler/../../Managers/./Manager.hpp \
 Engine/Framework/././Scheduler/../../Managers/./TaskManager.hpp \
 Engine/Framework/././Scheduler/../../Managers/./../../Utilities/Logger.hpp \
 Engine/Framework/././Scheduler/../../../Systems/SystemInterface.hpp \
 Engine/Framework/././Scheduler/../../../Systems/System.hpp \
 Engine/Framework/././Scheduler/../../../Systems/helixStructures.hpp \
 Engine/Framework/././Scheduler/../../../Systems/../Engine/Managers/IntBundle.hpp \
 Engine/Framework/././Scheduler/../../../Systems/../Engine/Managers/./MgrBundle.hpp \
 Engine/Framework/././Scheduler/../../../Systems/../Engine/Managers/././StateManagerInterface.hpp \
 Engine/Framework/././Scheduler/../../../Systems/../Engine/Managers/./././StateManager.hpp \
 Engine/Framework/././Scheduler/../../../Systems/../Engine/Managers/././ServiceManagerInterface.hpp \
 Engine/Framework/././Scheduler/../../../Systems/../Engine/Managers/./././ServiceManager.hpp \
 Engine/Framework/././Scheduler/../../../Systems/../Engine/Managers/././EnvironmentManagerInterface.hpp \
 Engine/Framework/././Scheduler/../../../Systems/../Engine/Managers/./././EnvironmentManager.hpp \
 Engine/Framework/././Scheduler/../../../Systems/../Engine/Managers/././PlatformManagerInterface.hpp \
 Engine/Framework/././Scheduler/../../../Systems/../Engine/Managers/./././PlatformManager.hpp \
 Engine/Framework/././UEntities/UScene.hpp
	$(CC) $(CFLAGS) ./Engine/Framework/Framework.cpp $(FFLAGS)


../obj/Scheduler.o: Engine/Framework/Scheduler/Scheduler.cpp \
 Engine/Framework/Scheduler/Scheduler.hpp \
 Engine/Framework/Scheduler/../../Managers/TaskManagerInterface.hpp \
 Engine/Framework/Scheduler/../../Managers/./ManagerInterface.hpp \
 Engine/Framework/Scheduler/../../Managers/./Manager.hpp \
 Engine/Framework/Scheduler/../../Managers/./TaskManager.hpp \
 Engine/Framework/Scheduler/../../Managers/./../../Utilities/Logger.hpp \
 Engine/Framework/Scheduler/../../../Systems/SystemInterface.hpp \
 Engine/Framework/Scheduler/../../../Systems/System.hpp \
 Engine/Framework/Scheduler/../../../Systems/helixStructures.hpp \
 Engine/Framework/Scheduler/../../../Systems/../Engine/Managers/IntBundle.hpp \
 Engine/Framework/Scheduler/../../../Systems/../Engine/Managers/./MgrBundle.hpp \
 Engine/Framework/Scheduler/../../../Systems/../Engine/Managers/././StateManagerInterface.hpp \
 Engine/Framework/Scheduler/../../../Systems/../Engine/Managers/./././StateManager.hpp \
 Engine/Framework/Scheduler/../../../Systems/../Engine/Managers/././ServiceManagerInterface.hpp \
 Engine/Framework/Scheduler/../../../Systems/../Engine/Managers/./././ServiceManager.hpp \
 Engine/Framework/Scheduler/../../../Systems/../Engine/Managers/././EnvironmentManagerInterface.hpp \
 Engine/Framework/Scheduler/../../../Systems/../Engine/Managers/./././EnvironmentManager.hpp \
 Engine/Framework/Scheduler/../../../Systems/../Engine/Managers/././PlatformManagerInterface.hpp \
 Engine/Framework/Scheduler/../../../Systems/../Engine/Managers/./././PlatformManager.hpp
	$(CC) $(CFLAGS) ./Engine/Framework/Scheduler/Scheduler.cpp $(FFLAGS)


../obj/Engine.o: Engine/Engine.cpp Engine/./Engine.hpp \
 Engine/././Framework/Framework.hpp \
 Engine/././Framework/./Scheduler/Scheduler.hpp \
 Engine/././Framework/./Scheduler/../../Managers/TaskManagerInterface.hpp \
 Engine/././Framework/./Scheduler/../../Managers/./ManagerInterface.hpp \
 Engine/././Framework/./Scheduler/../../Managers/./Manager.hpp \
 Engine/././Framework/./Scheduler/../../Managers/./TaskManager.hpp \
 Engine/././Framework/./Scheduler/../../Managers/./../../Utilities/Logger.hpp \
 Engine/././Framework/./Scheduler/../../../Systems/SystemInterface.hpp \
 Engine/././Framework/./Scheduler/../../../Systems/System.hpp \
 Engine/././Framework/./Scheduler/../../../Systems/helixStructures.hpp \
 Engine/././Framework/./Scheduler/../../../Systems/../Engine/Managers/IntBundle.hpp \
 Engine/././Framework/./Scheduler/../../../Systems/../Engine/Managers/./MgrBundle.hpp \
 Engine/././Framework/./Scheduler/../../../Systems/../Engine/Managers/././StateManagerInterface.hpp \
 Engine/././Framework/./Scheduler/../../../Systems/../Engine/Managers/./././StateManager.hpp \
 Engine/././Framework/./Scheduler/../../../Systems/../Engine/Managers/././ServiceManagerInterface.hpp \
 Engine/././Framework/./Scheduler/../../../Systems/../Engine/Managers/./././ServiceManager.hpp \
 Engine/././Framework/./Scheduler/../../../Systems/../Engine/Managers/././EnvironmentManagerInterface.hpp \
 Engine/././Framework/./Scheduler/../../../Systems/../Engine/Managers/./././EnvironmentManager.hpp \
 Engine/././Framework/./Scheduler/../../../Systems/../Engine/Managers/././PlatformManagerInterface.hpp \
 Engine/././Framework/./Scheduler/../../../Systems/../Engine/Managers/./././PlatformManager.hpp \
 Engine/././Framework/./UEntities/UScene.hpp
	$(CC) $(CFLAGS) ./Engine/Engine.cpp $(FFLAGS)


../obj/SceneExtension.o: Systems/EntityExtensions/SceneExtension.cpp \
 Systems/EntityExtensions/SceneExtension.hpp \
 Systems/EntityExtensions/../helixStructures.hpp
	$(CC) $(CFLAGS) ./Systems/EntityExtensions/SceneExtension.cpp $(FFLAGS)


../obj/ObjectExtension.o: Systems/EntityExtensions/ObjectExtension.cpp \
 Systems/EntityExtensions/ObjectExtension.hpp \
 Systems/EntityExtensions/../helixStructures.hpp
	$(CC) $(CFLAGS) ./Systems/EntityExtensions/ObjectExtension.cpp $(FFLAGS)


../obj/LogicObject.o: Systems/Logic/LogicObject.cpp \
 Systems/Logic/./LogicObject.hpp \
 Systems/Logic/./../EntityExtensions/ObjectExtension.hpp \
 Systems/Logic/./../EntityExtensions/../helixStructures.hpp
	$(CC) $(CFLAGS) ./Systems/Logic/LogicObject.cpp $(FFLAGS)


../obj/LogicSystemInterface.o: Systems/Logic/LogicSystemInterface.cpp \
 Systems/Logic/./LogicSystemInterface.hpp \
 Systems/Logic/././LogicSystem.hpp Systems/Logic/././../System.hpp \
 Systems/Logic/././../helixStructures.hpp \
 Systems/Logic/././../../Engine/Managers/IntBundle.hpp \
 Systems/Logic/././../../Engine/Managers/./MgrBundle.hpp \
 Systems/Logic/././../../Engine/Managers/././TaskManagerInterface.hpp \
 Systems/Logic/././../../Engine/Managers/./././ManagerInterface.hpp \
 Systems/Logic/././../../Engine/Managers/./././Manager.hpp \
 Systems/Logic/././../../Engine/Managers/./././TaskManager.hpp \
 Systems/Logic/././../../Engine/Managers/./././../../Utilities/Logger.hpp \
 Systems/Logic/././../../Engine/Managers/././StateManagerInterface.hpp \
 Systems/Logic/././../../Engine/Managers/./././StateManager.hpp \
 Systems/Logic/././../../Engine/Managers/././ServiceManagerInterface.hpp \
 Systems/Logic/././../../Engine/Managers/./././ServiceManager.hpp \
 Systems/Logic/././../../Engine/Managers/././EnvironmentManagerInterface.hpp \
 Systems/Logic/././../../Engine/Managers/./././EnvironmentManager.hpp \
 Systems/Logic/././../../Engine/Managers/././PlatformManagerInterface.hpp \
 Systems/Logic/././../../Engine/Managers/./././PlatformManager.hpp \
 Systems/Logic/./././LogicScene.hpp \
 Systems/Logic/./././../EntityExtensions/SceneExtension.hpp \
 Systems/Logic/././././LogicObject.hpp \
 Systems/Logic/././././../EntityExtensions/ObjectExtension.hpp \
 Systems/Logic/./../SystemInterface.hpp
	$(CC) $(CFLAGS) ./Systems/Logic/LogicSystemInterface.cpp $(FFLAGS)


../obj/LogicSystem.o: Systems/Logic/LogicSystem.cpp \
 Systems/Logic/./LogicSystem.hpp Systems/Logic/./../System.hpp \
 Systems/Logic/./../helixStructures.hpp \
 Systems/Logic/./../../Engine/Managers/IntBundle.hpp \
 Systems/Logic/./../../Engine/Managers/./MgrBundle.hpp \
 Systems/Logic/./../../Engine/Managers/././TaskManagerInterface.hpp \
 Systems/Logic/./../../Engine/Managers/./././ManagerInterface.hpp \
 Systems/Logic/./../../Engine/Managers/./././Manager.hpp \
 Systems/Logic/./../../Engine/Managers/./././TaskManager.hpp \
 Systems/Logic/./../../Engine/Managers/./././../../Utilities/Logger.hpp \
 Systems/Logic/./../../Engine/Managers/././StateManagerInterface.hpp \
 Systems/Logic/./../../Engine/Managers/./././StateManager.hpp \
 Systems/Logic/./../../Engine/Managers/././ServiceManagerInterface.hpp \
 Systems/Logic/./../../Engine/Managers/./././ServiceManager.hpp \
 Systems/Logic/./../../Engine/Managers/././EnvironmentManagerInterface.hpp \
 Systems/Logic/./../../Engine/Managers/./././EnvironmentManager.hpp \
 Systems/Logic/./../../Engine/Managers/././PlatformManagerInterface.hpp \
 Systems/Logic/./../../Engine/Managers/./././PlatformManager.hpp \
 Systems/Logic/././LogicScene.hpp \
 Systems/Logic/././../EntityExtensions/SceneExtension.hpp \
 Systems/Logic/./././LogicObject.hpp \
 Systems/Logic/./././../EntityExtensions/ObjectExtension.hpp
	$(CC) $(CFLAGS) ./Systems/Logic/LogicSystem.cpp $(FFLAGS)


../obj/LogicScene.o: Systems/Logic/LogicScene.cpp Systems/Logic/./LogicScene.hpp \
 Systems/Logic/./../EntityExtensions/SceneExtension.hpp \
 Systems/Logic/./../EntityExtensions/../helixStructures.hpp \
 Systems/Logic/././LogicObject.hpp \
 Systems/Logic/././../EntityExtensions/ObjectExtension.hpp
	$(CC) $(CFLAGS) ./Systems/Logic/LogicScene.cpp $(FFLAGS)


../obj/GraphicSystem.o: Systems/Graphics/GraphicSystem.cpp \
 Systems/Graphics/./GraphicSystem.hpp Systems/Graphics/./../System.hpp \
 Systems/Graphics/./../helixStructures.hpp \
 Systems/Graphics/./../../Engine/Managers/IntBundle.hpp \
 Systems/Graphics/./../../Engine/Managers/./MgrBundle.hpp \
 Systems/Graphics/./../../Engine/Managers/././TaskManagerInterface.hpp \
 Systems/Graphics/./../../Engine/Managers/./././ManagerInterface.hpp \
 Systems/Graphics/./../../Engine/Managers/./././Manager.hpp \
 Systems/Graphics/./../../Engine/Managers/./././TaskManager.hpp \
 Systems/Graphics/./../../Engine/Managers/./././../../Utilities/Logger.hpp \
 Systems/Graphics/./../../Engine/Managers/././StateManagerInterface.hpp \
 Systems/Graphics/./../../Engine/Managers/./././StateManager.hpp \
 Systems/Graphics/./../../Engine/Managers/././ServiceManagerInterface.hpp \
 Systems/Graphics/./../../Engine/Managers/./././ServiceManager.hpp \
 Systems/Graphics/./../../Engine/Managers/././EnvironmentManagerInterface.hpp \
 Systems/Graphics/./../../Engine/Managers/./././EnvironmentManager.hpp \
 Systems/Graphics/./../../Engine/Managers/././PlatformManagerInterface.hpp \
 Systems/Graphics/./../../Engine/Managers/./././PlatformManager.hpp \
 Systems/Graphics/././GraphicScene.hpp \
 Systems/Graphics/./././GraphicObject.hpp \
 Systems/Graphics/./././../EntityExtensions/ObjectExtension.hpp \
 Systems/Graphics/././../EntityExtensions/SceneExtension.hpp
	$(CC) $(CFLAGS) ./Systems/Graphics/GraphicSystem.cpp $(FFLAGS)


../obj/GraphicScene.o: Systems/Graphics/GraphicScene.cpp \
 Systems/Graphics/GraphicScene.hpp Systems/Graphics/./GraphicObject.hpp \
 Systems/Graphics/./../EntityExtensions/ObjectExtension.hpp \
 Systems/Graphics/./../EntityExtensions/../helixStructures.hpp \
 Systems/Graphics/../EntityExtensions/SceneExtension.hpp
	$(CC) $(CFLAGS) ./Systems/Graphics/GraphicScene.cpp $(FFLAGS)


../obj/GraphicSystemInterface.o: Systems/Graphics/GraphicSystemInterface.cpp \
 Systems/Graphics/./GraphicSystemInterface.hpp \
 Systems/Graphics/././GraphicSystem.hpp \
 Systems/Graphics/././../System.hpp \
 Systems/Graphics/././../helixStructures.hpp \
 Systems/Graphics/././../../Engine/Managers/IntBundle.hpp \
 Systems/Graphics/././../../Engine/Managers/./MgrBundle.hpp \
 Systems/Graphics/././../../Engine/Managers/././TaskManagerInterface.hpp \
 Systems/Graphics/././../../Engine/Managers/./././ManagerInterface.hpp \
 Systems/Graphics/././../../Engine/Managers/./././Manager.hpp \
 Systems/Graphics/././../../Engine/Managers/./././TaskManager.hpp \
 Systems/Graphics/././../../Engine/Managers/./././../../Utilities/Logger.hpp \
 Systems/Graphics/././../../Engine/Managers/././StateManagerInterface.hpp \
 Systems/Graphics/././../../Engine/Managers/./././StateManager.hpp \
 Systems/Graphics/././../../Engine/Managers/././ServiceManagerInterface.hpp \
 Systems/Graphics/././../../Engine/Managers/./././ServiceManager.hpp \
 Systems/Graphics/././../../Engine/Managers/././EnvironmentManagerInterface.hpp \
 Systems/Graphics/././../../Engine/Managers/./././EnvironmentManager.hpp \
 Systems/Graphics/././../../Engine/Managers/././PlatformManagerInterface.hpp \
 Systems/Graphics/././../../Engine/Managers/./././PlatformManager.hpp \
 Systems/Graphics/./././GraphicScene.hpp \
 Systems/Graphics/././././GraphicObject.hpp \
 Systems/Graphics/././././../EntityExtensions/ObjectExtension.hpp \
 Systems/Graphics/./././../EntityExtensions/SceneExtension.hpp \
 Systems/Graphics/./../SystemInterface.hpp
	$(CC) $(CFLAGS) ./Systems/Graphics/GraphicSystemInterface.cpp $(FFLAGS)


../obj/GraphicObject.o: Systems/Graphics/GraphicObject.cpp \
 Systems/Graphics/GraphicObject.hpp \
 Systems/Graphics/../EntityExtensions/ObjectExtension.hpp \
 Systems/Graphics/../EntityExtensions/../helixStructures.hpp
	$(CC) $(CFLAGS) ./Systems/Graphics/GraphicObject.cpp $(FFLAGS)


../obj/SystemInterface.o: Systems/SystemInterface.cpp \
 Systems/SystemInterface.hpp Systems/System.hpp \
 Systems/helixStructures.hpp Systems/../Engine/Managers/IntBundle.hpp \
 Systems/../Engine/Managers/./MgrBundle.hpp \
 Systems/../Engine/Managers/././TaskManagerInterface.hpp \
 Systems/../Engine/Managers/./././ManagerInterface.hpp \
 Systems/../Engine/Managers/./././Manager.hpp \
 Systems/../Engine/Managers/./././TaskManager.hpp \
 Systems/../Engine/Managers/./././../../Utilities/Logger.hpp \
 Systems/../Engine/Managers/././StateManagerInterface.hpp \
 Systems/../Engine/Managers/./././StateManager.hpp \
 Systems/../Engine/Managers/././ServiceManagerInterface.hpp \
 Systems/../Engine/Managers/./././ServiceManager.hpp \
 Systems/../Engine/Managers/././EnvironmentManagerInterface.hpp \
 Systems/../Engine/Managers/./././EnvironmentManager.hpp \
 Systems/../Engine/Managers/././PlatformManagerInterface.hpp \
 Systems/../Engine/Managers/./././PlatformManager.hpp
	$(CC) $(CFLAGS) ./Systems/SystemInterface.cpp $(FFLAGS)


../obj/System.o: Systems/System.cpp Systems/System.hpp \
 Systems/helixStructures.hpp Systems/../Engine/Managers/IntBundle.hpp \
 Systems/../Engine/Managers/./MgrBundle.hpp \
 Systems/../Engine/Managers/././TaskManagerInterface.hpp \
 Systems/../Engine/Managers/./././ManagerInterface.hpp \
 Systems/../Engine/Managers/./././Manager.hpp \
 Systems/../Engine/Managers/./././TaskManager.hpp \
 Systems/../Engine/Managers/./././../../Utilities/Logger.hpp \
 Systems/../Engine/Managers/././StateManagerInterface.hpp \
 Systems/../Engine/Managers/./././StateManager.hpp \
 Systems/../Engine/Managers/././ServiceManagerInterface.hpp \
 Systems/../Engine/Managers/./././ServiceManager.hpp \
 Systems/../Engine/Managers/././EnvironmentManagerInterface.hpp \
 Systems/../Engine/Managers/./././EnvironmentManager.hpp \
 Systems/../Engine/Managers/././PlatformManagerInterface.hpp \
 Systems/../Engine/Managers/./././PlatformManager.hpp
	$(CC) $(CFLAGS) ./Systems/System.cpp $(FFLAGS)


clean:
	rm ../obj/*.o
../obj/:
	mkdir ../obj/
OBJDIR:|../obj/

$(EXEC): OBJDIR ../obj/Logger.o \
../obj/main.o \
../obj/TaskManagerInterface.o \
../obj/EnvironmentManager.o \
../obj/IntBundle.o \
../obj/StateManager.o \
../obj/ServiceManager.o \
../obj/PlatformManagerInterface.o \
../obj/TaskManager.o \
../obj/ServiceManagerInterface.o \
../obj/MgrBundle.o \
../obj/Manager.o \
../obj/EnvironmentManagerInterface.o \
../obj/StateManagerInterface.o \
../obj/PlatformManager.o \
../obj/UObject.o \
../obj/UScene.o \
../obj/Framework.o \
../obj/Scheduler.o \
../obj/Engine.o \
../obj/SceneExtension.o \
../obj/ObjectExtension.o \
../obj/LogicObject.o \
../obj/LogicSystemInterface.o \
../obj/LogicSystem.o \
../obj/LogicScene.o \
../obj/GraphicSystem.o \
../obj/GraphicScene.o \
../obj/GraphicSystemInterface.o \
../obj/GraphicObject.o \
../obj/SystemInterface.o \
../obj/System.o 
	$(CC) $(LFLAGS) -o $(EXEC) ../obj/*.o $(LIBS)


.DEFAULT_GOAL:=$(EXEC)

.PHONY:clean OBJDIR
