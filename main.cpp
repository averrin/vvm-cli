#include <iostream>
#include <string>
#include <memory>

#include "format.h"
// #include "args.hpp"
#include "vvm/analyzer.hpp"
#include "vvm/devices/rng.hpp"
#include "vvm/devices/video.hpp"

int main(int argc, char *argv[]) {
  // args::ArgumentParser parser(
  //     "Vortex VM. Toy virtual machine for toy assembly.", "");
  // args::HelpFlag help(parser, "help", "Display this help menu", {'h', "help"});
  // args::Positional<std::string> input_file(parser, "input_file",
  //                                          "Input code file");


  auto path = ".";
  // parser.ParseCLI(argc, argv);

  auto core = std::make_shared<Core>(
      Core([&](MemoryContainer b, unsigned int pointer) {
      }));
  // core->setInterruptHandler(INT_PRINT, printHandler);
  auto analyzer = analyzer::Analyzer();

  auto filename = "input.vvmc";
  auto vm_filename = "result.vvm";

  auto dis_code = analyzer.parseFile(filename);

  core->compile(dis_code);
  auto rng = std::make_shared<RngDevice>(4);
  auto video = std::make_shared<VideoDevice>(32, 16);
  core->addDevice(rng);
  core->addDevice(video);

  core->saveBytes(fmt::format("{}.init", vm_filename));
  core->execCode();
  core->saveBytes(vm_filename);

    return 0;
}
