#ifndef HITABLELISTH
#define HITABLELISTH

#include "hitable.h"  // include hitable class

// hitable_list class definition, inherits from hitable
class hitable_list: public hitable {
public:
    // default constructor
    hitable_list() {}

    // constructor: init with list of hitable objects and its size
    hitable_list(hitable **l, int n) {
        list = l;
        list_size = n;
    }

    // checks if ray hits any object in the list between t_min and t_max
    virtual bool hit(const ray& r, float t_min, float t_max, hit_record& rec) const;

    hitable **list;  // list of hitable objects
    int list_size;   // size of list
};

// implementation of hit() for hitable_list
bool hitable_list::hit(const ray& r, float t_min, float t_max, hit_record& rec) const {
    hit_record temp_rec;
    bool hit_anything = false;
    double closest_so_far = t_max;

    // loop over all objects, find closest hit
    for(int i = 0; i < list_size; i++) {
        if(list[i]->hit(r, t_min, closest_so_far, temp_rec)) {
            hit_anything = true;
            closest_so_far = temp_rec.t;
            rec = temp_rec;
        }
    }

    return hit_anything;
}

#endif  // end preprocessor guard
