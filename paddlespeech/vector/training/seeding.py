# Copyright (c) 2021 PaddlePaddle Authors. All Rights Reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
from paddlespeech.s2t.utils.log import Log

logger = Log(__name__).getlog()
import random

import numpy as np
import paddle


def seed_everything(seed: int):
    """Seed paddle, random and np.random to help reproductivity."""
    paddle.seed(seed)
    random.seed(seed)
    np.random.seed(seed)
    logger.info(f"Set the seed of paddle, random, np.random to {seed}.")
