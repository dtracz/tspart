#pragma once

#include "API.hh"
#include "Points/PointsTools.hh"

class PointsMixin : public virtual API
{
public:

  ImageToScalarField& image_to_scalar_field(DataPromise<sf::Texture>& data, Param<size_t> scale=2);
  ScalarFieldMassPrefixSum& scalar_field_mass_prefix_sum(DataPromise<ScalarField<uint8_t>>& data);

  PolylinePloterSaver& polyline_ploter_saver(DataPromise<Polyline>& data, Param<std::string> name=std::string(""));
  PolylineSVGSaver& polyline_svg_saver(DataPromise<Polyline>& data, Param<std::string> name=std::string(""));

  PointsGenerator& points_generator(DataPromise<ScalarField<uint8_t>>& data, Param<size_t> fill=12);
  PointsVoronoiDelaunay& points_voronoi_delaunay(DataPromise<Polyline>& data);

  PointsRelaxator& points_relaxator(
    DataPromise<Polyline>& data,
    DataPromise<VoronoiCells>& cells,
    DataPromise<ScalarField<MassElement>>& mass_field);

  HilbertPointsOrderer& hilbert_points_orderer(DataPromise<Polyline>& data);
  NearestNeighbourPointsOrderer& nearest_neighbour_points_orderer(DataPromise<Polyline>& data);
  MSTPointsOrderer& mst_points_orderer(
    DataPromise<Polyline>& data,
    DataPromise<DelaunayTriangulation>& graph);
  SkipPointsOrderer& skip_points_orderer(
    DataPromise<Polyline>& data,
    DataPromise<DelaunayTriangulation>& graph);

  PolylineVisualizer& polyline_visualizer(DataPromise<Polyline>& data);
  VoronoiCellsVisualizer& voronoi_cells_visualizer(
    DataPromise<Polyline>& data,
    DataPromise<VoronoiCells>& voronoi);
  DelaunayTriangulationVisualizer& delaunay_triangulation_visualizer(
    DataPromise<Polyline>& data,
    DataPromise<DelaunayTriangulation>& delaunay);

  DataPromise<Polyline>& n_voronoi_relaxation(
    DataPromise<Polyline>& data,
    DataPromise<ScalarField<MassElement>>& field,
    int n=1);

  DataPromise<Polyline>& mst_ordering(DataPromise<Polyline>& data);
  DataPromise<Polyline>& skip_ordering(DataPromise<Polyline>& data);
};
