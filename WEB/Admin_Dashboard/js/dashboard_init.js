!(function (a) {
    "use strict";
    a(function () {
        if (a("#bar").length) {
            var e = a("#bar").get(0).getContext("2d");
            e.height =20;
            new Chart(e, {
                type: "bar",
                data: {
                    labels: ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"],
                    datasets: [
                        {
                            label: "Revenue",
                            backgroundColor: "#1ccab8",
                            borderColor: "transparent",
                            borderWidth: 2,
                            categoryPercentage: 0.5,
                            hoverBackgroundColor: "#00d8c2",
                            hoverBorderColor: "transparent",
                            data: [30, 39, 20, 31, 41, 25, 20, 39, 20, 31, 41, 25],
                        },
                    ],
                },
                options: {
                    // responsive: !0,
                    responsive: true,
                    // maintainAspectRatio: !0,
                    maintainAspectRatio: false,
                    legend: { display: !1, labels: { fontColor: "#50649c" } },
                    tooltips: {
                        enabled: !0,
                        callbacks: {
                            label: function (e, a) {
                                return a.datasets[e.datasetIndex].label + " $ " + e.yLabel + "k";
                            },
                        },
                    },
                    scales: {
                        xAxes: [
                            {
                                barPercentage: 0.35,
                                categoryPercentage: 0.4,
                                display: !0,
                                gridLines: { color: "transparent", borderDash: [0], zeroLineColor: "transparent", zeroLineBorderDash: [2], zeroLineBorderDashOffset: [2] },
                                ticks: { fontColor: "#a4abc5", beginAtZero: !0, padding: 12 },
                            },
                        ],
                        yAxes: [
                            {
                                gridLines: { color: "#8997bd29", borderDash: [3], drawBorder: !1, drawTicks: !1, zeroLineColor: "#8997bd29", zeroLineBorderDash: [2], zeroLineBorderDashOffset: [2] },
                                ticks: {
                                    fontColor: "#a4abc5",
                                    beginAtZero: !0,
                                    padding: 12,
                                    callback: function (e) {
                                        if (!(e % 10)) return "$" + e + "k";
                                    },
                                },
                            },
                        ],
                    },
                },
            });
        }
    });
})(jQuery)





