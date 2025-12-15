#include "q8rf_button.h"
#include "esphome/core/log.h"

namespace esphome {
namespace q8rf {

static const char *TAG = "q8rf.button";

void Q8RFButton::setup() {
  controller_->compile_msg(
      q8rf_device_id_, q8rf_zone_id_, Q8RF_MSG_CMD_PAIR, msg_pair_);
  initialized_ = true;
}

void Q8RFButton::press_action() {
  if (!initialized_) {
    setup();
  }

  ESP_LOGI(TAG, "Send PAIR device: 0x%04X zone: %d",
           q8rf_device_id_, q8rf_zone_id_);
  controller_->send_msg(msg_pair_);
}

void Q8RFButton::set_q8rf_device_id(uint16_t id) {
  q8rf_device_id_ = id;
}

void Q8RFButton::set_q8rf_zone_id(uint16_t id) {
  q8rf_zone_id_ = id;
}

void Q8RFButton::set_controller(Q8RFController *controller) {
  controller_ = controller;
}

void Q8RFButton::dump_config() {
  ESP_LOGCONFIG(TAG, "Q8RF Device ID: 0x%04X", q8rf_device_id_);
  ESP_LOGCONFIG(TAG, "Q8RF Zone ID: %d", q8rf_zone_id_);
}

}  // namespace q8rf
}  // namespace esphome
