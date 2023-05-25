#pragma once

#include "envoy/extensions/filters/http/gcp_authn/v3/gcp_authn.pb.h"
#include "envoy/extensions/filters/http/gcp_authn/v3/gcp_authn.pb.validate.h"

#include "source/extensions/filters/http/common/factory_base.h"
#include "source/extensions/filters/http/gcp_authn/gcp_authn_filter.h"

namespace Envoy {
namespace Extensions {
namespace HttpFilters {
namespace GcpAuthn {

class GcpAuthnFilterFactory
    : public Common::DualFactoryBase<
          envoy::extensions::filters::http::gcp_authn::v3::GcpAuthnFilterConfig>,
      public Logger::Loggable<Logger::Id::filter> {
public:
  GcpAuthnFilterFactory() : DualFactoryBase(std::string(FilterName)) {}

  Http::FilterFactoryCb createFilterFactoryFromProtoTyped(
      const envoy::extensions::filters::http::gcp_authn::v3::GcpAuthnFilterConfig& config,
      const std::string& stats_prefix, DualInfo dual_info,
      Server::Configuration::ServerFactoryContext& context) override;
};

using UpstreamGcpAuthnFilterFactory = GcpAuthnFilterFactory;

} // namespace GcpAuthn
} // namespace HttpFilters
} // namespace Extensions
} // namespace Envoy
