#pragma once
namespace redro {
class Scene {
public:
    virtual ~Scene() = default;
    virtual void update(float delta_seconds) = 0;
};
}