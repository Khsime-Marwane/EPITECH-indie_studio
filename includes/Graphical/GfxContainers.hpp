//
// Author: Marwane Khsime 
// Date: 2017-06-05 07:38:18 
//
// Last Modified by:   Marwane Khsime 
// Last Modified time: 2017-06-05 07:38:18
//

#ifndef GFX_CONTAINERS_HPP
# define GFX_CONTAINERS_HPP

#include <string>
#include <utility>
#include <vector>

#include "irr/irrlicht.h"

namespace indie
{

    // Scene infos
    struct SceneInfos {
        irr::f32    startX;
        irr::f32    startY;
        irr::f32    width;
        irr::f32    height;
        irr::f32    depth;
    };

    struct GfxInfos {
        SceneInfos  scene;
        std::size_t flor;
    };

    // Container for Scenes
    struct SceneContainer
    {
        SceneContainer()
                    : _scene() {
        }
        SceneContainer(const std::vector<std::pair<irr::scene::IMesh *,
                                                   irr::scene::IMeshSceneNode *> > &scene)
                                                   : _scene(scene) {
                                                    
        }
        SceneContainer(SceneContainer &&scene)
                    : _scene(scene._scene) {
                    
        }
        SceneContainer(const SceneContainer &scene)
                    : _scene(scene._scene) {

        }

        SceneContainer &operator=(SceneContainer &&) = default;
        SceneContainer &operator=(const SceneContainer &) = default;
        ~SceneContainer() {

        }

        std::vector<std::pair<irr::scene::IMesh *,
                              irr::scene::IMeshSceneNode *> >   _scene;
    };

    // Container For Models (meshes)
    struct  MeshContainer {

        MeshContainer()
                    : mesh(NULL), frameSequences() {
        }

        MeshContainer(irr::scene::IAnimatedMesh *_mesh,
                      std::vector<std::pair<size_t, size_t> > _frameSequences)
                      : mesh(_mesh), frameSequences(_frameSequences) {
        }

        MeshContainer(const MeshContainer &mc)
            : mesh(mc.mesh), frameSequences(mc.frameSequences) {
        }

        MeshContainer &operator=(const MeshContainer &mc) {
            this->mesh = mc.mesh;
            this->frameSequences = mc.frameSequences;
            return *this;
        }

        MeshContainer(MeshContainer &&) = default;
        MeshContainer &operator=(MeshContainer &&) = default;
        ~MeshContainer() {

        };

        irr::scene::IAnimatedMesh                 *mesh;
        std::vector<std::pair<size_t, size_t> >   frameSequences;
    };

    // Container for nodes (objects)
    struct  NodeContainer {

        NodeContainer()
            : id(0), node(NULL) {
        }

        NodeContainer(size_t _id, irr::scene::IAnimatedMeshSceneNode *_node)
            : id(_id), node(_node) {
        }

        NodeContainer(const NodeContainer &nc)
            : id(nc.id), node(nc.node) {
        }

        NodeContainer &operator=(const NodeContainer &nc) {
            this->id = nc.id;
            this->node = nc.node;
            return *this;
        }

        NodeContainer(NodeContainer &&) = default;
        NodeContainer &operator=(NodeContainer &&) = default;
        ~NodeContainer() {

        };

        size_t                                      id;
        irr::scene::IAnimatedMeshSceneNode          *node;

    };

}

#endif // GFX_CONTAINERS_HPP
