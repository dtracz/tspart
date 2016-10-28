#include <sstream>
#include "Image/Loader.hh"

ImageLoader::ImageLoader(Logger& log)
: out(this)
, filename_input(this)
, logger(log)
{
  filename_input.connect(filename_manual);
}

void ImageLoader::compute()
{
  logger.enter(Logger::Level::Info, "Image loading");
  {
    std::ostringstream stream;
    stream<<"Filename: "<<filename_input.get_data();
    logger.log(Logger::Level::Verbose, stream.str().c_str());
  }
  sf::Image tmp;
  if(!tmp.loadFromFile(filename_input.get_data()))
  {
    logger.log(Logger::Level::Error, "Invalid image file!");
    exit(-1);
  }
  data_hook(out).loadFromImage(tmp);
  logger.exit();
}
