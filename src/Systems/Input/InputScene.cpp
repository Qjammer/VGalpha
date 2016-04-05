#include "InputScene.hpp"

InputScene::InputScene():SceneExtension(EntityType::INPUT){

}

bool InputScene::isKeyPressed(sf::Keyboard::Key _key){
	return sf::Keyboard::isKeyPressed(_key);
}
