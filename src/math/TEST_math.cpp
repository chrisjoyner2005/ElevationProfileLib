#include "TEST_math.h"

void run_math_tests(Logger& log) {

    log.append(TEST_Geodetic2Vector());
    log.append(TEST_Vector2Geodetic());
}

Status TEST_Geodetic2Vector() {

    string func_name = "Geodetic2Vector";

    GeoDDCoordinate pt01(0, 0);
    GeoDDCoordinate pt02(45, 45);
    GeoDDCoordinate pt03(90, 90);

    vec p01 = CoordinateUtils::Geodetic2Vector(pt01);
    vec p02 = CoordinateUtils::Geodetic2Vector(pt02);
    vec p03 = CoordinateUtils::Geodetic2Vector(pt03);

    if (norm(p01, vec(0, 0, 1)) > 0.001)
        return Status(func_name, 0, "Vector has invalid value");

    if (norm(p02, vec(0.500, 0.707107, 0.500)) > 0.001)
        return Status(func_name, 0, "Vector has invalid value");

    if (norm(p03, vec(0, 1, 0)) > 0.001)
        return Status(func_name, 0, "Vector has invalid value");

    return Status(func_name, 1, "");
}

Status TEST_Vector2Geodetic() {

    string func_name = "Vector2Geodetic";

    vec p01(0, 0, 1);
    vec p02(0, 1, 0);
    vec p03(1, 0, 0);
    vec p04(0.500, 0.707107, 0.500);
    vec p05(-1, 0, 0);

    GeoDDCoordinate pt01 = CoordinateUtils::Vector2Geodetic(p01);
    GeoDDCoordinate pt02 = CoordinateUtils::Vector2Geodetic(p02);
    GeoDDCoordinate pt03 = CoordinateUtils::Vector2Geodetic(p03);
    GeoDDCoordinate pt04 = CoordinateUtils::Vector2Geodetic(p04);
    GeoDDCoordinate pt05 = CoordinateUtils::Vector2Geodetic(p05);

    if (CoordinateUtils::norm(pt01, GeoDDCoordinate(0.0, 0.0)) > 0.00001)
        return Status(func_name, 0, "Coordinate has invalid value");

    if (CoordinateUtils::norm(pt02, GeoDDCoordinate(90.0, 0.0)) > 0.00001)
        return Status(func_name, 0, "Coordinate has invalid value");

    if (CoordinateUtils::norm(pt03, GeoDDCoordinate(0.0, 90.0)) > 0.00001)
        return Status(func_name, 0, "Coordinate has invalid value");

    if (CoordinateUtils::norm(pt04, GeoDDCoordinate(45.0, 45.0)) > 0.0001)
        return Status(func_name, 0, "Coordinate has invalid value");

    if (CoordinateUtils::norm(pt05, GeoDDCoordinate(0.0, -90.0)) > 0.0001)
        return Status(func_name, 0, "Coordinate has invalid value");
    
    
    
    return Status(func_name, 1, "");
}

