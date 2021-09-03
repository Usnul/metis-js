#include "emscripten.h"
#include "include/metis.h"
#include <stdlib.h> // required for malloc definition

/**
*/
EMSCRIPTEN_KEEPALIVE
int metis_part_graph_kway(
    idx_t nvtxs, // number of vertices
    idx_t ncon, // number of constraints
    idx_t* xadj, // Pointers to the locally stored vertices
    idx_t* adjncy, // Array that stores the adjacency lists of nvtxs
    idx_t* vwgt, // Vertex weights
    idx_t* vsize, // Vertex sizes for min-volume formulation
    idx_t* adjwgt, // Array that stores the weights of the adjacency lists
    idx_t nparts, // The number of partitions
    real_t* tpwgts, // The target partition weights
    real_t* ubvec, // ??
    idx_t* options, // options vector with pointers to relevant things
    idx_t* objval, // Objective value will be written here
    idx_t* part // where partitions should be written to, size equal to number of vertices
    ) {

    int status = METIS_PartGraphKway(
        &nvtxs,
        &ncon,
        xadj,
        adjncy,
        vwgt, 
        vsize, 
        adjwgt,
        &nparts,
        tpwgts,
        ubvec,
        options,
        objval,
        part
   );

  return status;
}

EMSCRIPTEN_KEEPALIVE
int metis_part_graph_recursive(
    idx_t nvtxs, // number of vertices
    idx_t ncon, // number of constraints
    idx_t* xadj, // Pointers to the locally stored vertices
    idx_t* adjncy, // Array that stores the adjacency lists of nvtxs
    idx_t* vwgt, // Vertex weights
    idx_t* vsize, // Vertex sizes for min-volume formulation
    idx_t* adjwgt, // Array that stores the weights of the adjacency lists
    idx_t nparts, // The number of partitions
    real_t* tpwgts, // The target partition weights
    real_t* ubvec, // ??
    idx_t* options, // options vector with pointers to relevant things
    idx_t* objval, // Objective value will be written here
    idx_t* part // where partitions should be written to, size equal to number of vertices
    ) {

    int status = METIS_PartGraphRecursive(
        &nvtxs,
        &ncon,
        xadj,
        adjncy,
        vwgt,
        vsize,
        adjwgt,
        &nparts,
        tpwgts,
        ubvec,
        options,
        objval,
        part
        );

    return status;
}

EMSCRIPTEN_KEEPALIVE
uint8_t* create_buffer(int byte_size) {
  return malloc(byte_size);
}

EMSCRIPTEN_KEEPALIVE
void destroy_buffer(uint8_t* p) {
  free(p);
}