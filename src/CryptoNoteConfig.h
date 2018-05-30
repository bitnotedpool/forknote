// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
//
// This file is part of Bytecoin.
//
// Bytecoin is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Bytecoin is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Bytecoin. If not, see <http://www.gnu.org/licenses/>.
#pragma once
#include <cstddef>
#include <cstdint>
#include <limits>
namespace CryptoNote {
	namespace parameters {
		const uint32_t		KILL_HEIGHT = 0;
		const uint32_t		CRYPTONOTE_MAX_BLOCK_NUMBER = 800000000;
		const size_t		CRYPTONOTE_MAX_BLOCK_BLOB_SIZE = 800000000;
		const size_t		CRYPTONOTE_MAX_TX_SIZE = 1000000000;
		const uint64_t		CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 8842;
		const uint32_t		CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW = 8;
		const uint64_t		CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT = 1680; //7*240
		const size_t		BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW = 60;
		const uint64_t		MONEY_SUPPLY = 8888888880000;
		const size_t		CRYPTONOTE_DISPLAY_DECIMAL_POINT = 4;
		const uint64_t		MINIMUM_FEE = 10;
		const uint64_t		DEFAULT_FEE = 20;
		const size_t		MIN_MIXIN = 8;
		const uint32_t		MIXIN_START_HEIGHT = 10;
		const uint8_t		MANDATORY_MIXIN_BLOCK_VERSION = 0;
		const uint32_t		MANDATORY_TRANSACTION = 0;
		const unsigned		EMISSION_SPEED_FACTOR = 19;
		const uint64_t		GENESIS_BLOCK_REWARD = 0;
		const uint64_t		TAIL_EMISSION_REWARD = 80000;
		const size_t		CRYPTONOTE_COIN_VERSION = 1;
		const uint32_t		ZAWY_DIFFICULTY_BLOCK_INDEX = 0; //old
		const uint32_t		ZAWY_DIFFICULTY_LAST_BLOCK = 0; //old
		const uint32_t		ZAWY_LWMA_DIFFICULTY_BLOCK_INDEX = 10;
		const uint32_t		ZAWY_LWMA_DIFFICULTY_LAST_BLOCK = 0;
		const size_t		ZAWY_LWMA_DIFFICULTY_N = 0;
		const uint32_t		BUGGED_ZAWY_DIFFICULTY_BLOCK_INDEX = 0; //old

		static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");

		const size_t		CRYPTONOTE_REWARD_BLOCKS_WINDOW = 100;
		const size_t		CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE = 100000; //size of block (bytes) after which reward for block calculated using block size
		const size_t		CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2 = 20000;
		const size_t		CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1 = 10000;
		const size_t		CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE;
		const size_t		CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE = 600;

		const uint64_t		DEFAULT_DUST_THRESHOLD = 10;
		const uint64_t		MAX_TRANSACTION_SIZE_LIMIT = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 110 / 100 - CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE;

		const uint64_t		DIFFICULTY_TARGET = 240;
		const uint64_t		EXPECTED_NUMBER_OF_BLOCKS_PER_DAY = 360;
		const size_t		DIFFICULTY_WINDOW = 360;
		const size_t		DIFFICULTY_WINDOW_V1 = DIFFICULTY_WINDOW;
		const size_t		DIFFICULTY_WINDOW_V2 = DIFFICULTY_WINDOW;
		const size_t		DIFFICULTY_CUT = 60; // timestamps to cut after sorting
		const size_t		DIFFICULTY_CUT_V1 = DIFFICULTY_CUT;
		const size_t		DIFFICULTY_CUT_V2 = DIFFICULTY_CUT;
		const size_t		DIFFICULTY_LAG = 15; // !!!
		const size_t		DIFFICULTY_LAG_V1 = DIFFICULTY_LAG;
		const size_t		DIFFICULTY_LAG_V2 = DIFFICULTY_LAG;

		static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

		const size_t		MAX_BLOCK_SIZE_INITIAL = 20480;
		const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR = 100 * 1024;
		const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;
		const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS = 1;
		const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;
		const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME = 86400; //one day
		const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = 691200; //oct day
		const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7; // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx
		const size_t FUSION_TX_MAX_SIZE = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_CURRENT * 30 / 100;
		const size_t FUSION_TX_MIN_INPUT_COUNT = 12;
		const size_t FUSION_TX_MIN_IN_OUT_COUNT_RATIO = 4;
		const uint32_t KEY_IMAGE_CHECKING_BLOCK_INDEX = 0;
		const uint32_t		UPGRADE_HEIGHT_V2 = 1; //!!!!!!!!!!!!!
		const uint32_t		UPGRADE_HEIGHT_V3 = 2; //!!!!!!!!!!!!!
		const unsigned		UPGRADE_VOTING_THRESHOLD = 88; //%
		const uint32_t		UPGRADE_VOTING_WINDOW = 360; //blocks
		const uint32_t		UPGRADE_WINDOW = 360; //blocks

		static_assert(0 < UPGRADE_VOTING_THRESHOLD && UPGRADE_VOTING_THRESHOLD <= 100, "Bad UPGRADE_VOTING_THRESHOLD");
		static_assert(UPGRADE_VOTING_WINDOW > 1, "Bad UPGRADE_VOTING_WINDOW");

		const char			CRYPTONOTE_BLOCKS_FILENAME[] = "octoblocks.bin";
		const char			CRYPTONOTE_BLOCKINDEXES_FILENAME[] = "octoblockindexes.bin";
		const char			CRYPTONOTE_POOLDATA_FILENAME[] = "octopoolstate.bin";
		const char			P2P_NET_DATA_FILENAME[] = "octop2pstate.bin";
		const char			MINER_CONFIG_FILE_NAME[] = "octominer_conf.json";
		const char			GENESIS_COINBASE_TX_HEX[] = "010801ff0001e2e68a08029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd0880712101f22ed4c7f6120806dfbad2504a2e044bc999184c6424f77ccd9408425404fdd6"; //no premine in genesis block
	} // parameters
	const char		CRYPTONOTE_NAME[] = "octonit";
	const uint8_t	TRANSACTION_VERSION_1 = 1;
	const uint8_t	TRANSACTION_VERSION_2 = 2;
	const uint8_t	CURRENT_TRANSACTION_VERSION = 1;
	const uint8_t	BLOCK_MAJOR_VERSION_1 = 1;
	const uint8_t	BLOCK_MAJOR_VERSION_2 = 2;
	const uint8_t	BLOCK_MAJOR_VERSION_3 = 3;
	const uint8_t	BLOCK_MINOR_VERSION_0 = 0;
	const uint8_t	BLOCK_MINOR_VERSION_1 = 1;
	const size_t	BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT = 10000; //by default, blocks ids count in synchronizing
	const size_t	BLOCKS_SYNCHRONIZING_DEFAULT_COUNT = 100; //by default, blocks count in blocks downloading
	const size_t	COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT = 1000;
	const int		P2P_DEFAULT_PORT = 18001;
	const int		RPC_DEFAULT_PORT = 18002;
	const size_t	P2P_LOCAL_WHITE_PEERLIST_LIMIT = 1000;
	const size_t	P2P_LOCAL_GRAY_PEERLIST_LIMIT = 5000;
	const size_t	P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE = 32 * 1024 * 1024; //32MB
	const uint32_t	P2P_DEFAULT_CONNECTIONS_COUNT = 8;
	const size_t	P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT = 70; //%
	const uint32_t	P2P_DEFAULT_HANDSHAKE_INTERVAL = 60; //s
	const uint32_t	P2P_DEFAULT_PACKET_MAX_SIZE = 50000000; //bytes maximum packet size
	const uint32_t	P2P_DEFAULT_PEERS_IN_HANDSHAKE = 250;
	const uint32_t	P2P_DEFAULT_CONNECTION_TIMEOUT = 5000; //ms
	const uint32_t	P2P_DEFAULT_PING_CONNECTION_TIMEOUT = 2000; //ms
	const uint64_t	P2P_DEFAULT_INVOKE_TIMEOUT = 120000; //ms
	const size_t	P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT = 8000; //ms
	const uint32_t	P2P_FAILED_ADDR_FORGET_SECONDS = 3600; //s
	const uint32_t	P2P_IP_BLOCKTIME = 88888; //s
	const uint32_t	P2P_IP_FAILS_BEFORE_BLOCK = 10;
	const uint32_t	P2P_IDLE_CONNECTION_KILL_INTERVAL = 300; //5m
	const char		P2P_STAT_TRUSTED_PUB_KEY[] = "";
	const char* const SEED_NODES[] = {
		"127.0.0.1:18001",
		"127.0.0.1:18002",
		"127.0.0.1:18003"
	};
	struct CheckpointData {
		uint32_t index;
		const char* blockId;
	};
	const std::initializer_list<CheckpointData> CHECKPOINTS = {
		/*{ 1000, "" },{ 2000, "" }*/
	};
} // CryptoNote
#define ALLOW_DEBUG_COMMANDS