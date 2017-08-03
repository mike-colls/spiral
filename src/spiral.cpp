#include "io2d_plot.hpp"

int main()
{
    namespace io2d = std::experimental::io2d;
    using namespace io2d_plot;

    const int width{500};
    const int height{300};
    io2d::image_surface image{io2d::format::argb32, width, height};
    image.paint( io2d::brush{io2d::rgba_color::white} );

    const int margin{10};
    xy_plot plot{width - 2 * margin, height - 2 * margin, margin, margin};
    plot.back_color( io2d::rgba_color::lemon_chiffon );
    plot.draw_grid(false);

    auto spiral_line = plot.add_line();
    const int max_angle = 720;
    for( int angle = 0; angle < max_angle; angle += 20 )
    {
        spiral_line->add_point(
            {static_cast<float>( angle * cos( angle * io2d::pi<double> / 180.0 ) / max_angle ),
            static_cast<float>( angle * sin( angle * io2d::pi<double> / 180.0 ) / max_angle)} );
    }

    plot.draw( image );
    image.save( experimental::filesystem::path( "spiral.png" ), io2d::image_data_format::png );
    return 0;
}
