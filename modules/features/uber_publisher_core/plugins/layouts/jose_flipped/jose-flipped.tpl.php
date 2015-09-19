<div class="panel-jose-flipped clearfix panel-display" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="row">
    <?php if ($content['top']): ?>
      <div class="panel-region-top panel-panel col-sm-12">
        <div class="inside">
          <div class="row">
            <?php print $content['top']; ?>
          </div>
        </div>
      </div>
    <?php endif; ?>

    <div class="panel-region-middle panel-panel col-sm-12">
      <div class="row">
        <div class="container">
          <div class="row">
            <div class="panel-region-middle--left panel-panel col-sm-8">
              <div class="row">
                <div class="panel-region-middle--left-center-top panel-panel col-sm-12">
                  <div class="inside">
                    <div class="row">
                      <?php print $content['center_top']; ?>
                    </div>
                  </div>
                </div>
              </div>

              <div class="row">
                <div class="panel-region-middle--left-center-left panel-panel col-sm-6">
                  <div class="inside">
                    <div class="row">
                      <?php print $content['center_left']; ?>
                    </div>
                  </div>
                </div>
                <div class="panel-region-middle--left-center-right panel-panel col-sm-6">
                  <div class="inside">
                    <div class="row">
                      <?php print $content['center_right']; ?>
                    </div>
                  </div>
                </div>
              </div>

              <div class="row">
                <div class="panel-region-middle--left-center-bottom panel-panel col-sm-12">
                  <div class="inside">
                    <div class="row">
                      <div class="inside"><?php print $content['center_bottom']; ?></div>
                    </div>
                  </div>
                </div>
              </div>
            </div>

            <div class="panel-region-middle--right panel-panel col-sm-4">
              <div class="inside">
                <div class="row">
                  <div class="inside"><?php print $content['right']; ?></div>
                </div>
              </div>
            </div>
          </div>
        </div>
      </div>
    </div>

    <?php if ($content['bottom']): ?>
      <div class="panel-region-bottom panel-panel col-sm-12">
          <div class="row">
            <div class="inside">
              <?php print $content['bottom']; ?>
            </div>
          </div>
      </div>
    <?php endif; ?>
  </div>
</div>
