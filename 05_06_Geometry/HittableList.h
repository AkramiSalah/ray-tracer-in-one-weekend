#pragma once
#include "Hittable.h"
#include <memory>
#include <vector>


class HittableList : public Hittable{
public:

    // this class uses rule of zero. becuse im using a ptr wrapper that handeles everythign(all five of the big five) for me.

    void add( const std::shared_ptr<Hittable>& obj){
        objects.push_back(obj);
    }

    bool hit(const Ray& ray, Interval ray_t, HitRecord& rec) const override{
        HitRecord tempHitRecord;
        bool hasHit = false;
        auto currentClosest = ray_t.max;

        for(const auto& obj : objects){
            if(obj->hit(ray, Interval(ray_t.min, currentClosest), tempHitRecord)){
                hasHit = true;
                currentClosest = tempHitRecord.t;
                rec = tempHitRecord;
            }
        }

        return hasHit;
    }


private:
    std::vector<std::shared_ptr<Hittable>> objects;
};


