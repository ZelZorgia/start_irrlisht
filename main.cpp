#include "irrlicht/irrlicht.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

int main() {
    IrrlichtDevice *device =
            createDevice( video::EDT_SOFTWARE, dimension2d<u32>(640, 480), 16,
                          false, false, false, 0);
    if (!device)
        return 1;
    device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");
    video::IVideoDriver* driver = device->getVideoDriver();
    scene::ISceneManager* smgr = device->getSceneManager();
    gui::IGUIEnvironment* gui = device->getGUIEnvironment();
/*    device->getFileSystem()->addFileArchive("Bomberman.zip");
    scene::IAnimatedMesh* mesh = smgr->getMesh("BomberMan.3ds");*/
    scene::IAnimatedMesh* mesh = smgr->getMesh("bomberman.obj");
    scene::ISceneNode* node = 0;
    if (mesh)
        node = smgr->addOctreeSceneNode(mesh->getMesh(0), 0, -1, 1024*1024);
    if (node)
        node->setPosition(core::vector3df(100,-50,100));
    smgr->addCameraSceneNodeFPS();
    device->getCursorControl()->setVisible(false);
    while(device->run())
    {
        if (device->isWindowActive())
        {
            driver->beginScene(true, true, video::SColor(0,0,0,0));
            smgr->drawAll();
            driver->endScene();
        }
        else
            device->yield();
    }
    device->drop();
    return 0;
}
