#ifndef _BE_DESIGNER_LOGGER_H_
#define _BE_DESIGNER_LOGGER_H_

#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>

namespace logging = boost::log;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace keywords = boost::log::keywords;

static src::severity_logger< logging::trivial::severity_level > lg;

namespace bd {
	class Logger {
	public:
		static void init() {
			logging::add_file_log(
					keywords::open_mode = std::ios::app,
					keywords::file_name = "eibs_%N.log",
					keywords::rotation_size = 10 * 1024 * 1024,
					keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0),
					keywords::format = "[%TimeStamp%]: %Message%"
					);
			logging::core::get()->set_filter(
					logging::trivial::severity >= logging::trivial::info
					);
			logging::add_common_attributes();
		}
	public:
		template<typename T>
		static void _debug(T msg) {						
			BOOST_LOG_SEV(lg, logging::trivial::debug) << msg;
		}
		template<typename T>
		static void _info(T msg) {			
			BOOST_LOG_SEV(lg, logging::trivial::info) << msg;
		}
		template<typename T>
		static void _error(T msg) {			
			BOOST_LOG_SEV(lg, logging::trivial::error) << msg;
		}
	};
}
#endif