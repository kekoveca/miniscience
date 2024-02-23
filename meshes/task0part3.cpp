#include <set>
#include <gmsh.h>

int main(int argc, char **argv)
{
    gmsh::initialize();

    gmsh::model::add("cylinder");

    double lc = 1e-2;

    gmsh::model::geo::addPoint(0, 0, 0, lc, 1);

    gmsh::model::geo::addPoint(.1, 0, 0, lc, 2);
    gmsh::model::geo::addPoint(0, .1, 0, lc, 3);
    gmsh::model::geo::addPoint(-0.1, 0, 0, lc, 4);
    gmsh::model::geo::addPoint(0, -.1, 0, lc, 5);

    gmsh::model::geo::addCircleArc(2, 1, 3, 1);
    gmsh::model::geo::addCircleArc(3, 1, 4, 2);
    gmsh::model::geo::addCircleArc(4, 1, 5, 3);
    gmsh::model::geo::addCircleArc(5, 1, 2, 4);

    gmsh::model::geo::addPoint(0, 0, .1, lc, 6);

    gmsh::model::geo::addPoint(.1, 0, .1, lc, 7);
    gmsh::model::geo::addPoint(0, .1, .1, lc, 8);
    gmsh::model::geo::addPoint(-0.1, 0, .1, lc, 9);
    gmsh::model::geo::addPoint(0, -.1, .1, lc, 10);

    gmsh::model::geo::addCircleArc(7, 6, 8, 5);
    gmsh::model::geo::addCircleArc(8, 6, 9, 6);
    gmsh::model::geo::addCircleArc(9, 6, 10, 7);
    gmsh::model::geo::addCircleArc(10, 6, 7, 8);

    for(int i = 1; i < 5; i++) 
        gmsh::model::geo::addLine(i + 1, i + 6, i + 8);

    gmsh::model::geo::addCurveLoop({1, 2, 3, 4}, 1);
    gmsh::model::geo::addPlaneSurface({1}, 1);

    gmsh::model::geo::addCurveLoop({5, 6, 7, 8}, 2);
    gmsh::model::geo::addPlaneSurface({2}, 2);

    gmsh::model::geo::addCurveLoop({1, 10, -5, -9}, 3);
    gmsh::model::geo::addSurfaceFilling({3}, 3);

    gmsh::model::geo::addCurveLoop({2, 11, -6, -10}, 4);
    gmsh::model::geo::addSurfaceFilling({4}, 4);

    gmsh::model::geo::addCurveLoop({3, 12, -7, -11}, 5);
    gmsh::model::geo::addSurfaceFilling({5}, 5);

    gmsh::model::geo::addCurveLoop({4, 9, -8, -12}, 6);
    gmsh::model::geo::addSurfaceFilling({6}, 6);

    gmsh::model::geo::addSurfaceLoop({1, 2, 3, 4, 5, 6}, 1);
    gmsh::model::geo::addVolume({1});

    gmsh::model::geo::synchronize();

    gmsh::model::mesh::generate(3);

    gmsh::write("cylinder.msh");

    std::set<std::string> args(argv, argv + argc);
    if(!args.count("-nopopup")) gmsh::fltk::run();

    gmsh::finalize();

    return 0;
}
