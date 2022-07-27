
// Copyright (c) 2017 Facebook Inc. (Soumith Chintala),
// All rights reserved.

#pragma once

#include "paddlespeech/audio/src/optional/optional.hpp"
#include "paddlespeech/audio/src/sox/utils.h"

namespace paddleaudio {
namespace sox_io {

auto get_effects(const tl::optional<int64_t>& frame_offset,
                 const tl::optional<int64_t>& num_frames)
    -> std::vector<std::vector<std::string>>;

using MetaDataTuple =
    std::tuple<int64_t, int64_t, int64_t, int64_t, std::string>;

tl::optional<MetaDataTuple> get_info_file(
    const std::string& path, const tl::optional<std::string>& format);

tl::optional<std::tuple<py::array, int64_t>> load_audio_file(
    const std::string& path,
    const tl::optional<int64_t>& frame_offset,
    const tl::optional<int64_t>& num_frames,
    tl::optional<bool> normalize,
    tl::optional<bool> channels_first,
    const tl::optional<std::string>& format);

void save_audio_file(const std::string& path,
                     py::array tensor,
                     int64_t sample_rate,
                     bool channels_first,
                     tl::optional<double> compression,
                     tl::optional<std::string> format,
                     tl::optional<std::string> encoding,
                     tl::optional<int64_t> bits_per_sample);

}  // namespace sox_io
}  // namespace paddleaudio
