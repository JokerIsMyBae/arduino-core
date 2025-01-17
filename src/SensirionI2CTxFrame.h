/*
 * Copyright (c) 2020, Sensirion AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of Sensirion AG nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef SENSIRION_I2C_TX_FRAME_H_
#define SENSIRION_I2C_TX_FRAME_H_

#include <stdint.h>
#include <stdlib.h>

#include "SensirionCrc.h"
#include "SensirionI2CCommunication.h"

/*
 * SensirionI2CTxFrame - Class which helps to build a correct I2C frame for
 * Sensirion Sensors. The different addDatatype() functions add the frame data
 * and the addCommand() function writes the command at the beginning. Using
 * these functions one can easily construct a I2C frame for Sensirion sensors.
 */
class SensirionI2CTxFrame {

    friend class SensirionI2CCommunication;

  public:
    /**
     * Constructor
     *
     * @param buffer     Buffer in which the send frame will be stored.
     * @param bufferSize Number of bytes in the buffer for the send frame.
     * @param poly       CRC polynomal to use. Defaults to 0x31 with init 0xFF
     *
     * @deprecated Use createWithUInt16Command() instead
     */
    SensirionI2CTxFrame(uint8_t buffer[], size_t bufferSize,
                        size_t numCommandBytes = 2);

    /**
     * addCommand() - Add command to the send frame.
     *
     * @param command Command to add to the send frame.
     *
     * @return        NoError on success, an error code otherwise
     *
     * @deprecated Use createWithUInt16Command() instead
     */
    uint16_t addCommand(uint16_t command);

    /**
     * addUInt16() - Add unsigned 16bit integer to the send frame.
     *
     * @param data Unsigned 16bit integer to add to the send frame.
     *
     * @return     NoError on success, an error code otherwise
     */
    uint16_t addUInt16(uint16_t data);

  private:
    uint16_t _addByte(uint8_t data);

    uint8_t* _buffer;
    size_t _bufferSize;
    size_t _index;
    size_t _numCommandBytes;
};

#endif /* SENSIRION_I2C_TX_FRAME_H_ */
