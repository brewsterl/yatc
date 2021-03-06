//////////////////////////////////////////////////////////////////////
// Yet Another Tibia Client
//////////////////////////////////////////////////////////////////////
//
//////////////////////////////////////////////////////////////////////
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//////////////////////////////////////////////////////////////////////

#ifndef __NETMESSAGE_H
#define __NETMESSAGE_H

#include <string>
#include "../fassert.h"
#include "../stdinttypes.h"

#define NETWORK_MESSAGE_SIZE 16384

class Position;

class NetworkMessage
{
	public:
		NetworkMessage(int accessType);
		~NetworkMessage() {}

		void reset();

		uint32_t getU32();
		uint16_t getU16();
		uint16_t inspectU16();
		uint8_t getU8();
		std::string getString();
		Position getPosition();

		bool getU32(uint32_t& v);
		bool getU16(uint16_t& v);
		bool inspectU16(uint16_t& v);
		bool getU8(uint8_t& v);
		bool getString(std::string& v);
		bool getPosition(Position& p);

		void addU32(uint32_t value);
		void addU16(uint16_t value);
		void addU8(uint8_t value);
		void addMessageType(uint8_t value){
			ASSERT(m_messageTypeAdded == false);
			ASSERT(m_messageTypeAdded = true);
			addU8(value);
		}
		void addString(const std::string& value) { addString(value.c_str()); }
		void addString(const char* value);
		void addRaw(const void* content, size_t amount);
		void addPosition(const Position& pos);
		void addPaddingBytes(uint32_t n);
		void addHeader();
		void addChecksum();

		uint32_t getChecksum(uint16_t offset = 0);

		void skipBytes(int size){
			m_readPos += size;
		}

		char* getBuffer(){ return m_buffer + m_start; }
		const char* getBuffer() const { return m_buffer + m_start; }
		char* getReadBuffer(){ return m_buffer + m_readPos; }
		const char* getReadBuffer() const { return m_buffer + m_readPos; }

		int getStart() const { return m_start;}

		int getReadPos() const { return m_readPos; }
		void setReadPos(int pos) { m_readPos = pos; }

		void setSize(int size) { m_size = size; }
		int getSize() const { return m_size; }
		void setReadSize(int size) { m_size = m_readPos + size; }
		int getReadSize() const { return m_size - m_readPos; }

		bool canRead(int bytes) const;
		bool canWrite(int bytes) const;

		bool eof() const { return !canRead(1);}

		enum{
			CAN_READ = 1,
			CAN_WRITE = 2
		};

		void setType(int v){ m_accessType = v; }
		int getType() const { return m_accessType; }

		bool isMessageTypeAdded() const { return m_messageTypeAdded; }

	protected:

		int m_accessType;
		int m_start;
		int m_size;
		int m_readPos;
		int m_writePos;
		char m_buffer[NETWORK_MESSAGE_SIZE];
		bool m_messageTypeAdded;
};

#endif
